#pragma once
#include <windows.h>
#include <TlHelp32.h>

#include "AeginaInfo.h"

namespace IDFind {
	Aegina::AeginaStatus FindProcessId(Aegina::_PAeginaInfo AeginaInfo);
	Aegina::AeginaStatus FindThreadId(Aegina::_PAeginaInfo AeginaInfo);
}
