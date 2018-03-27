﻿#pragma once

#include "UILib/BaseControl.h"
#include "UILib/TextFont.h"
#include "LuaLib/LuaTinker.h"

namespace jojogame {
class CStaticControl : public CBaseControl
{
public:
    static void RegisterFunctions(lua_State *L);

    CStaticControl();
    ~CStaticControl();

    bool IsAutoSize();
    bool IsBackgroundTransparent();
    int GetAlign();
    std::wstring GetText();
    CTextFont *GetFont();
    COLORREF GetTextColor();
    HBRUSH GetBackgroundBrush();

    void SetAutoSize(bool value);
    void SetBackgroundTransparent(bool value);
    void SetAlign(int align);
    void SetText(std::wstring text);
    void SetTextColor(COLORREF color);
    void SetBackgroundColor(COLORREF color);

    bool Create() override;
    void Destroy() override;

    void Show() override;

    static WNDPROC GetOriginalProc();
    static LRESULT CALLBACK OnControlProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    void _AutoSizing();

    CTextFont _font;

    bool _isAutoSize = true;
    bool _isBackgroundTransparent = true;

    int _align = 0; // 0 : left, 1 : right, 2 : center
    std::wstring _text = L"";

    COLORREF _textColor = RGB(0, 0, 0);
    COLORREF _backgroundColor = GetSysColor(COLOR_3DFACE);
    HBRUSH _backgroundBrush = CreateSolidBrush(GetSysColor(COLOR_3DFACE));

    static WNDPROC s_originalProc;
};

}
