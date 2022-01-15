#pragma once
#include <Windows.h>
#include <fstream>

#include "AeginaInfo.h"

#include "NtApi.h"
#include "NtStructs.h"

typedef HMODULE(_stdcall* tLoadLibraryA)(LPCSTR lpLibFileName);
typedef FARPROC(_stdcall* tGetProcAddress)(HMODULE hModule, LPCSTR lpProcName);
typedef BOOL(_stdcall* tDllMain)(HMODULE hModule, DWORD dwReason, LPARAM lParam);

#define RELOC_FLAG64(RelInfo) ((RelInfo >> 0x0C) == IMAGE_REL_BASED_DIR64)

typedef struct Loader {
	tLoadLibraryA pLoadLibraryA;
	tGetProcAddress pGetProcAddress;
	PVOID pbase;
} *PLoader;

namespace ManualMap {
	static void __stdcall Shellcode(PLoader l);
	Aegina::AeginaStatus ManualMap(Aegina::_PAeginaInfo AeginaInfo);
}
