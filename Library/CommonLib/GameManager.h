#pragma once

#define WM_STOP_DELAY (WM_USER + 1)

#include "LuaLib\LuaTinker.h"

#include <windows.h>
#include <mutex>
#include <memory>

namespace jojogame {
class CME5File;

class CGameManager
{
public:
    static void RegisterFunctions(lua_State *L);

    CGameManager();
    ~CGameManager();

    int GetDesktopWidth();
    int GetDesktopHeight();
    int Clock();

    COLORREF Color(int r, int g, int b);

    void Quit();

    void Delay(int time);
    void StopDelay();

    CME5File *OpenFile(std::wstring path);
    void CloseFile(CME5File *file);

    static CGameManager& GetInstance();
private:
    static std::once_flag s_onceFlag;
    static std::unique_ptr<CGameManager> s_sharedGameManager;
};
}
