#include "reframework/API.h"
#include "reframework/Hooks.h"
#include <Windows.h>

namespace reframework {

static bool g_initialized = false;

void OnInit()
{
    if (g_initialized) return;
    g_initialized = true;

    // Install RE Engine hooks
    Hooks::Install();
}

void OnFrame()
{
    if (!g_initialized) return;
    // Per-frame update — Lua callbacks are dispatched here
}

uintptr_t FindGameObject(const std::wstring& name)
{
    // Stub: real impl walks the RE Engine scene graph
    (void)name;
    return 0;
}

uintptr_t GetComponent(uintptr_t gameObject, const std::wstring& type)
{
    (void)gameObject; (void)type;
    return 0;
}

} // namespace reframework