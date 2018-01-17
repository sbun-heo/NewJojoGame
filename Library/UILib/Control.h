#pragma once

#include <Windows.h>
#include <string>

namespace jojogame {
class  CControl
{
public:
    CControl();
    virtual ~CControl();

    CControl(const CControl&) = delete;
    CControl& operator=(const CControl&) = delete;

    bool bold() const;
    bool enabled() const;
    bool italic() const;
    bool underline() const;
    bool visible() const;
    std::wstring fontName() const;
    int fontSize() const;
    int width() const;
    int height() const;
    int x() const;
    int y() const;
    LONG style() const;
    std::wstring createFunction() const;
    std::wstring destroyFunction() const;
    std::wstring clickFunction() const;
    HWND parentHwnd() const;

    void setBold(bool bold);
    void setItalic(bool italic);
    void setUnderline(bool underline);
    void setFontName(std::wstring fontName);
    void setFontSize(int fontSize);
    void setStyle(LONG style);
    void setVisible(bool visible);
    void setEnabled(bool enabled);
    void setY(int top);
    void setX(int left);
    void setWidth(int width);
    void setHeight(int height);
    void setCreateFunction(std::wstring createFunction);
    void setDestroyFunction(std::wstring destroyFunction);
    void setClickFunction(std::wstring clickFunction);

    /**
     * \brief Control �� ��Ÿ���ϴ�.
     */
    void show();

    /**
     * \brief Control �� ����ϴ�.
     */
    void hide();

    /**
     * \brief parentControl �� ����� ��ġ�� �ű�ϴ�.
     */
    void moveToCenter();

    virtual void destroy() = 0;

    /**
     * \brief Lua �� ����մϴ�.
     */
    static void registerToLua();

protected:
    void resetFont();

    bool _visible = false;
    bool _enabled = true;
    HWND _hwnd = nullptr;
    HWND _parentHwnd = nullptr;
    SIZE _size;
    POINT _position;
    LONG _style = 0;
    HFONT _font = nullptr;
    bool _bold = false;
    bool _italic = false;
    bool _underline = false;
    int _fontSize = 12;

    std::wstring _fontName = L"����";
    std::wstring _createFunction = L"";
    std::wstring _destroyFunction = L"";
    std::wstring _clickFunction = L"";
};
}
