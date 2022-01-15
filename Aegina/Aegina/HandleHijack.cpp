#include "HandleHijack.h"

Aegina::AeginaStatus HandleHijack::HijackHandle(Aegina::_PAeginaInfo AeginaInfo) {
	PSYSTEM_HANDLE_INFORMATION pShi = HandleHijack::RecvSystemHandleList();

	if (pShi == nullptr) {
		return Aegina::AeginaStatus::HIJACK_HANDLE_FAILURE;
	}

	for (ULONG i = 0; i < pShi->HandleCount; i++) {
		if ((HANDLE)pShi->Handles->Handle == INVALID_HANDLE_VALUE) {
			continue;
		}
		if (pShi->Handles[i].ObjectTypeNumber != HANDLE_TYPE_PROCESS) {
			continue;
		}
		if (pShi->Handles[i].ProcessId == AeginaInfo->pid) {
			continue;
		}
		HANDLE procHandle = OpenProcess(PROCESS_DUP_HANDLE, 0, pShi->Handles[i].ProcessId);
		if (procHandle == INVALID_HANDLE_VALUE) {
			continue;
		}
		NtDuplicateObject(procHandle, (HANDLE)pShi->Handles[i].Handle, NtCurrentProcess, &AeginaInfo->hProc, PROCESS_ALL_ACCESS, 0, 0);
		if (AeginaInfo->hProc == INVALID_HANDLE_VALUE) {
			continue;
		}
		if (GetProcessId(AeginaInfo->hProc) != AeginaInfo->pid) {
			CloseHandle(AeginaInfo->hProc);
			continue;
		}
		break;
	}

	return Aegina::AeginaStatus::HIJACK_HANDLE_SUCCESS;
}

PSYSTEM_HANDLE_INFORMATION HandleHijack::RecvSystemHandleList(void) {
	PSYSTEM_HANDLE_INFORMATION shi = new SYSTEM_HANDLE_INFORMATION;

	ULONG temp;
	NtQuerySystemInformation(SystemHandleInformation, shi, sizeof(SYSTEM_HANDLE_INFORMATION), &temp);

	ULONG Size = shi->HandleCount * sizeof(SYSTEM_HANDLE) + sizeof(SYSTEM_HANDLE_INFORMATION);

	shi = (PSYSTEM_HANDLE_INFORMATION)malloc(Size);
	NtQuerySystemInformation(SystemHandleInformation, shi, Size, &temp);

	return shi;
}

