#include "TextFont.h"
#include "BaseControl.h"

namespace jojogame {
void CTextFont::RegisterFunctions(lua_State *L)
{
    LUA_BEGIN(CTextFont, "_TextFont");

    LUA_METHOD(IsBold);
    LUA_METHOD(IsItalic);
    LUA_METHOD(IsUnderline);
    LUA_METHOD(GetFontName);
    LUA_METHOD(GetFontSize);

    LUA_METHOD(SetBold);
    LUA_METHOD(SetUnderline);
    LUA_METHOD(SetItalic);
    LUA_METHOD(SetFontName);
    LUA_METHOD(SetFontSize);
}

CTextFont::CTextFont(CBaseControl *control)
{
    _control = control;
    _fontName = L"����";
    _fontSize = 12;

    ResetFont();
}

CTextFont::~CTextFont()
{
    if (_font != nullptr)
    {
        DeleteFont(_font);
        _font = nullptr;
    }
}

HFONT CTextFont::GetHFont()
{
    return _font;
}

bool CTextFont::IsBold()
{
    return _isBold;
}

bool CTextFont::IsItalic()
{
    return _isItalic;
}

bool CTextFont::IsUnderline()
{
    return _isUnderline;
}

int CTextFont::GetFontSize()
{
    return _fontSize;
}

std::wstring CTextFont::GetFontName()
{
    return _fontName;
}

void CTextFont::SetBold(bool isBold)
{
    _isBold = isBold;
    ResetFont();
}

void CTextFont::SetItalic(bool isItalic)
{
    _isItalic = isItalic;
    ResetFont();
}

void CTextFont::SetUnderline(bool isUnderline)
{
    _isUnderline = isUnderline;
    ResetFont();
}

void CTextFont::SetFontSize(int fontSize)
{
    _fontSize = fontSize;
    ResetFont();
}

void CTextFont::SetFontName(std::wstring fontName)
{
    _fontName = fontName;
    ResetFont();
}

void CTextFont::ResetFont()
{
    if (_font != nullptr)
    {
        DeleteFont(_font);
        _font = nullptr;
    }

    _font = CreateFontW(_fontSize,
                        0,
                        0,
                        0,
                        FW_NORMAL,
                        static_cast<DWORD>(_isItalic),
                        static_cast<DWORD>(_isUnderline),
                        static_cast<DWORD>(_isBold),
                        HANGEUL_CHARSET,
                        0,
                        0,
                        0,
                        VARIABLE_PITCH | FF_ROMAN,
                        _fontName.c_str());

    HWND controlHWnd = _control->GetHWnd();
    if (controlHWnd != nullptr)
    {
        SendMessage(controlHWnd, WM_SETFONT, (WPARAM) _font, (LPARAM) TRUE);

        RECT rect;
        SetRect(&rect, _control->GetX(), _control->GetY(), _control->GetX() + _control->GetWidth(),
                _control->GetY() + _control->GetHeight());
        InvalidateRect(controlHWnd, &rect, true);
    }
}
}