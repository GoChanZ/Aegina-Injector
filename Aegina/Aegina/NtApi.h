#pragma once
#include <windows.h>

#pragma comment(lib, "ntdll.lib")

#include "NtStructs.h"
#include <ntstatus.h>

#define NtCurrentProcess ( (HANDLE)(LONG_PTR) -1 ) 

extern "C" NTSTATUS NTAPI NtQueryInformationProcess(
	IN HANDLE               ProcessHandle,
	IN ULONG ProcessInformationClass,
	OUT PVOID               ProcessInformation,
	IN ULONG                ProcessInformationLength,
	OUT PULONG              ReturnLength
);

extern "C" NTSTATUS NTAPI NtQueryInformationThread(
	IN HANDLE               ThreadHandle,
	IN ULONG ThreadInformationClass,
	OUT PVOID               ThreadInformation,
	IN ULONG                ThreadInformationLength,
	OUT PULONG              ReturnLength OPTIONAL
);

extern "C"  NTSTATUS NTAPI NtQuerySystemInformation(
	IN SYSTEM_INFO_CLASS SystemInformationClass,
	OUT PVOID               SystemInformation,
	IN ULONG                SystemInformationLength,
	OUT PULONG              ReturnLength OPTIONAL
);

extern "C" NTSTATUS NTAPI NtDuplicateObject(
	IN  HANDLE SourceProcessHandle,
	IN  HANDLE SourceHandle,
	IN  HANDLE TargetProcessHandle OPTIONAL,
	OUT PHANDLE TargetHandle OPTIONAL,
	IN  ACCESS_MASK DesiredAccess,
	IN  ULONG HandleAttributes,
	IN  ULONG Options
);

extern "C"  NTSTATUS NTAPI NtClose(
	IN HANDLE               ObjectHandle
);

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(
	ULONG Privilege,
	BOOLEAN Enable,
	BOOLEAN CurrentThread,
	PBOOLEAN Enabled
);

extern "C" NTSTATUS NTAPI NtOpenProcess(
	PHANDLE            ProcessHandle,
	ACCESS_MASK        DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PCLIENT_ID         ClientId
);