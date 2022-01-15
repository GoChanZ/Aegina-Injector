#pragma once
#include <windows.h>
#include <iostream>

namespace Aegina {
	typedef enum class AeginaStatus {
		STATUS_SUCCESSFUL_INJECTION,
		FILE_LOAD_ERROR,
		ID_FAILURE,
		ID_SUCCESS,
		HIJACK_HANDLE_SUCCESS,
		HIJACK_HANDLE_FAILURE,
		MEMORY_ALLOCATION_FAILURE,
		THREAD_FAILURE,
		WRITE_MEMORY_FAILURE,
		MEMORY_PROTECTION_FAILURE,
		INVALID_PROCESS,
		NTAPI_FAILURE,
		MANUAL_MAP_SUCCESS
	};

	typedef struct _AeginaInfo {
		const char* DllPath;
		const char* ProcessName;
		uint32_t pid;
		uint32_t tid;
		BOOL Log;
		HANDLE hProc;
	} *_PAeginaInfo;
}
