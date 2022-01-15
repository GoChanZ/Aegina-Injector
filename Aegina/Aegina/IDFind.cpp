#include "IDFind.h"

Aegina::AeginaStatus IDFind::FindProcessId(Aegina::_PAeginaInfo AeginaInfo) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap == INVALID_HANDLE_VALUE) {
		return Aegina::AeginaStatus::ID_FAILURE;
	}

	PROCESSENTRY32 PE32;
	PE32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnap, &PE32)) {
		while (Process32Next(hSnap, &PE32)) {
			if (strcmp(AeginaInfo->ProcessName, PE32.szExeFile) == 0) {
				AeginaInfo->pid = PE32.th32ProcessID;
				break;
			}
		}
	}

	CloseHandle(hSnap);
	return Aegina::AeginaStatus::ID_SUCCESS;
}

Aegina::AeginaStatus IDFind::FindThreadId(Aegina::_PAeginaInfo AeginaInfo) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	if (hSnap == INVALID_HANDLE_VALUE) {
		return Aegina::AeginaStatus::ID_FAILURE;
	}

	THREADENTRY32 TE32;
	TE32.dwSize = sizeof(THREADENTRY32);

	if (Thread32First(hSnap, &TE32)) {
		while (Thread32Next(hSnap, &TE32)) {
			if (TE32.th32OwnerProcessID == AeginaInfo->pid) {
				AeginaInfo->tid = TE32.th32ThreadID;
				break;
			}
		}
	}
	CloseHandle(hSnap);

	return Aegina::AeginaStatus::ID_SUCCESS;
}
