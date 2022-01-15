#include "Aegina.h"

Aegina::AeginaStatus AeginaInject::Inject(const char* DllPath, const char* Target) {
    BOOLEAN e;
    RtlAdjustPrivilege(SeDebugPrivilege, TRUE, FALSE, &e);

    Aegina::_AeginaInfo Ae;
    ZeroMemory(&Ae, sizeof(Ae));

    Ae.DllPath = DllPath;
    Ae.ProcessName = Target;

    Aegina::AeginaStatus status;

    status = IDFind::FindProcessId(&Ae);
    if (status != Aegina::AeginaStatus::ID_SUCCESS) {
        return status;
    }

    if (Ae.pid == 0) {
        return Aegina::AeginaStatus::INVALID_PROCESS;
    }

    status = HandleHijack::HijackHandle(&Ae);
    if (status != Aegina::AeginaStatus::HIJACK_HANDLE_SUCCESS) {
        return status;
    }


    status = ManualMap::ManualMap(&Ae);
    if (status != Aegina::AeginaStatus::MANUAL_MAP_SUCCESS) {
        return status;
    }

    return Aegina::AeginaStatus::STATUS_SUCCESSFUL_INJECTION;
}
