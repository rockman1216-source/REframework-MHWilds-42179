#include <Windows.h>
#include "reframework/API.h"

// REFramework entry point — loaded as dinput8.dll by RE Engine games
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        // Initialize REFramework on a background thread to avoid loader lock
        CreateThread(nullptr, 0, [](LPVOID) -> DWORD {
            reframework::OnInit();
            return 0;
        }, nullptr, 0, nullptr);
        break;

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}