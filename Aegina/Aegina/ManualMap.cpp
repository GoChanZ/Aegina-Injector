#include "ManualMap.h"

Aegina::AeginaStatus ManualMap::ManualMap(Aegina::_PAeginaInfo AeginaInfo) {
	HANDLE hFile = CreateFileA(AeginaInfo->DllPath, GENERIC_ALL, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	DWORD FileSize = GetFileSize(hFile, 0);

	PVOID DllMem = VirtualAlloc(0, FileSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!ReadFile(hFile, DllMem, FileSize, 0, 0)) {
		CloseHandle(hFile);
		return Aegina::AeginaStatus::FILE_LOAD_ERROR;
	}

	IMAGE_DOS_HEADER* DosHeader = (IMAGE_DOS_HEADER*)DllMem;
	PIMAGE_NT_HEADERS NtHeaders = PIMAGE_NT_HEADERS((uintptr_t)DllMem + DosHeader->e_lfanew);
	PIMAGE_SECTION_HEADER pSectHeader = IMAGE_FIRST_SECTION(NtHeaders);


	if (DosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
		CloseHandle(hFile);
		return Aegina::AeginaStatus::FILE_LOAD_ERROR;
	}

	PVOID pTargetBase = VirtualAllocEx(AeginaInfo->hProc, nullptr, NtHeaders->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if (!pTargetBase) {
		CloseHandle(hFile);
		return Aegina::AeginaStatus::MEMORY_ALLOCATION_FAILURE;
	}

	DWORD oldp = 0;
	if (!VirtualProtectEx(AeginaInfo->hProc, pTargetBase, NtHeaders->OptionalHeader.SizeOfImage, PAGE_EXECUTE_READWRITE, &oldp)) {
		CloseHandle(hFile);
		return Aegina::AeginaStatus::MEMORY_PROTECTION_FAILURE;
	}

	Loader data;
	data.pLoadLibraryA = &LoadLibraryA;
	data.pGetProcAddress = &GetProcAddress;

	data.pbase = pTargetBase;


	if (!WriteProcessMemory(AeginaInfo->hProc, pTargetBase, DllMem, 0x1000, nullptr)) {
		VirtualFreeEx(AeginaInfo->hProc, pTargetBase, 0, MEM_RELEASE);
		CloseHandle(hFile);
		return Aegina::AeginaStatus::WRITE_MEMORY_FAILURE;
	}

	IMAGE_SECTION_HEADER* pSectionHeader = IMAGE_FIRST_SECTION(NtHeaders);
	for (UINT i = 0; i != NtHeaders->FileHeader.NumberOfSections; ++i, ++pSectionHeader) {
		if (pSectionHeader->SizeOfRawData) {
			if (!WriteProcessMemory(AeginaInfo->hProc, (PVOID)((uintptr_t)pTargetBase + pSectionHeader->VirtualAddress), (LPVOID)((uintptr_t)DllMem + pSectionHeader->PointerToRawData), pSectionHeader->SizeOfRawData, nullptr)) {
				VirtualFreeEx(AeginaInfo->hProc, pTargetBase, 0, MEM_RELEASE);
				CloseHandle(hFile);
				return Aegina::AeginaStatus::WRITE_MEMORY_FAILURE;
			}
		}
	}

	PVOID LoaderAlloc = VirtualAllocEx(AeginaInfo->hProc, nullptr, sizeof(Loader), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if (!LoaderAlloc) {
		VirtualFreeEx(AeginaInfo->hProc, pTargetBase, 0, MEM_RELEASE);
		CloseHandle(hFile);
		return Aegina::AeginaStatus::MEMORY_ALLOCATION_FAILURE;
	}

	if (!WriteProcessMemory(AeginaInfo->hProc, LoaderAlloc, &data, sizeof(Loader), nullptr)) {
		VirtualFreeEx(AeginaInfo->hProc, pTargetBase, 0, MEM_RELEASE);
		VirtualFreeEx(AeginaInfo->hProc, LoaderAlloc, 0, MEM_RELEASE);
		CloseHandle(hFile);
		return Aegina::AeginaStatus::WRITE_MEMORY_FAILURE;
	}

	PVOID pShellcode = VirtualAllocEx(AeginaInfo->hProc, nullptr, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!pShellcode) {
		VirtualFreeEx(AeginaInfo->hProc, pTargetBase, 0, MEM_RELEASE);
		VirtualFreeEx(AeginaInfo->hProc, LoaderAlloc, 0, MEM_RELEASE);
		CloseHandle(hFile);
		return Aegina::AeginaStatus::MEMORY_ALLOCATION_FAILURE;
	}

	if (!WriteProcessMemory(AeginaInfo->hProc, pShellcode, Shellcode, 0x1000, nullptr)) {
		VirtualFreeEx(AeginaInfo->hProc, pTargetBase, 0, MEM_RELEASE);
		VirtualFreeEx(AeginaInfo->hProc, LoaderAlloc, 0, MEM_RELEASE);
		VirtualFreeEx(AeginaInfo->hProc, pShellcode, 0, MEM_RELEASE);
		CloseHandle(hFile);
		return Aegina::AeginaStatus::WRITE_MEMORY_FAILURE;
	}


	HANDLE hThread = CreateRemoteThread(AeginaInfo->hProc, nullptr, 0, (LPTHREAD_START_ROUTINE)pShellcode, LoaderAlloc, 0, nullptr);

	if (hThread == INVALID_HANDLE_VALUE) {
		return Aegina::AeginaStatus::THREAD_FAILURE;
	}

	CloseHandle(hFile);
	CloseHandle(hThread);

	return Aegina::AeginaStatus::MANUAL_MAP_SUCCESS;
}

void __stdcall ManualMap::Shellcode(PLoader l) {
	PVOID pBase = l->pbase;
	auto* pOpt = &reinterpret_cast<IMAGE_NT_HEADERS*>((uintptr_t)pBase + reinterpret_cast<IMAGE_DOS_HEADER*>((uintptr_t)pBase)->e_lfanew)->OptionalHeader;

	auto _LoadLibraryA = l->pLoadLibraryA;
	auto _GetProcAddress = l->pGetProcAddress;
	auto _DllMain = (tDllMain)((uintptr_t)pBase + pOpt->AddressOfEntryPoint);

	PVOID LocationDelta = (PVOID)((uintptr_t)pBase - pOpt->ImageBase);
	if (LocationDelta) {
		if (pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size) {
			auto* pRelocData = reinterpret_cast<IMAGE_BASE_RELOCATION*>((uintptr_t)pBase + pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
			const auto* pRelocEnd = reinterpret_cast<IMAGE_BASE_RELOCATION*>(reinterpret_cast<uintptr_t>(pRelocData) + pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size);
			while (pRelocData < pRelocEnd && pRelocData->SizeOfBlock) {
				UINT AmountOfEntries = (pRelocData->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
				WORD* pRelativeInfo = reinterpret_cast<WORD*>(pRelocData + 1);

				for (UINT i = 0; i != AmountOfEntries; ++i, ++pRelativeInfo) {
					if (RELOC_FLAG64(*pRelativeInfo)) {
						UINT_PTR* pPatch = reinterpret_cast<UINT_PTR*>((uintptr_t)pBase + pRelocData->VirtualAddress + ((*pRelativeInfo) & 0xFFF));
						*pPatch += reinterpret_cast<UINT_PTR>(LocationDelta);
					}
				}
				pRelocData = reinterpret_cast<IMAGE_BASE_RELOCATION*>(reinterpret_cast<BYTE*>(pRelocData) + pRelocData->SizeOfBlock);
			}
		}
	}

	if (pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size) {
		auto* pImportDescr = reinterpret_cast<IMAGE_IMPORT_DESCRIPTOR*>((uintptr_t)pBase + pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
		while (pImportDescr->Name) {
			char* szMod = reinterpret_cast<char*>((uintptr_t)pBase + pImportDescr->Name);
			HINSTANCE hDll = _LoadLibraryA(szMod);

			ULONG_PTR* pThunkRef = reinterpret_cast<ULONG_PTR*>((uintptr_t)pBase + pImportDescr->OriginalFirstThunk);
			ULONG_PTR* pFuncRef = reinterpret_cast<ULONG_PTR*>((uintptr_t)pBase + pImportDescr->FirstThunk);

			if (!pThunkRef)
				pThunkRef = pFuncRef;

			for (; *pThunkRef; ++pThunkRef, ++pFuncRef) {
				if (IMAGE_SNAP_BY_ORDINAL(*pThunkRef)) {
					*pFuncRef = (ULONG_PTR)_GetProcAddress(hDll, reinterpret_cast<char*>(*pThunkRef & 0xFFFF));
				}
				else {
					auto* pImport = reinterpret_cast<IMAGE_IMPORT_BY_NAME*>((uintptr_t)pBase + (*pThunkRef));
					*pFuncRef = (ULONG_PTR)_GetProcAddress(hDll, pImport->Name);
				}
			}
			++pImportDescr;
		}
	}

	if (pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size) {
		auto* pTLS = reinterpret_cast<IMAGE_TLS_DIRECTORY*>((uintptr_t)pBase + pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress);
		auto* pCallback = reinterpret_cast<PIMAGE_TLS_CALLBACK*>(pTLS->AddressOfCallBacks);
		for (; pCallback && *pCallback; ++pCallback)
			(*pCallback)(pBase, DLL_PROCESS_ATTACH, nullptr);
	}

	bool ExceptionSupportFailed = false;

	_DllMain((HMODULE)pBase, DLL_PROCESS_ATTACH, 0);
}
