﻿#pragma once
#include "BaseControl.h"
#include "TextFont.h"

namespace jojogame {
class CGroupBoxControl : public CBaseControl
{
public:
    static void RegisterFunctions(lua_State* L);

    CGroupBoxControl();
    virtual ~CGroupBoxControl();

    std::wstring GetText();
    CTextFont* GetFont();

    void SetText(std::wstring text);

    bool Create() override;

    static WNDPROC GetOriginalProc();
    static LRESULT CALLBACK OnControlProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    CTextFont _font;
    std::wstring _text;

    static WNDPROC s_originalProc;
};
}
