#pragma once
#include "Aegina.h"
#include "ManualMap.h"
#include "HandleHijack.h"
#include "IDFind.h"

namespace AeginaInject {
	Aegina::AeginaStatus Inject(const char* DllPath, const char* Target);
}