#include <Windows.h>
#include "Aegina.h"

extern "C" __declspec(dllexport) Aegina::AeginaStatus Inject(const char* DllPath, const char* Target) {
	return AeginaInject::Inject(DllPath, Target);
}
