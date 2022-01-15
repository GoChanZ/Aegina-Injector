#pragma once
#include <Windows.h>

#include "AeginaInfo.h"

#include "NtApi.h"
#include "NtStructs.h"

namespace HandleHijack {
	Aegina::AeginaStatus HijackHandle(Aegina::_PAeginaInfo AeginaInfo);
	PSYSTEM_HANDLE_INFORMATION RecvSystemHandleList(void);
}
