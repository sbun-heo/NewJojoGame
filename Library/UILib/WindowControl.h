#pragma once

#include "BaseControl.h"
#include "LuaLib\LuaTinker.h"

namespace jojogame {
class CMenubar;

class CWindowControl : public CBaseControl
{
public:
    static void RegisterFunctions(lua_State *L);

    CWindowControl();
    virtual ~CWindowControl();

    bool IsControlBox() const;
    bool IsMaxButton() const;
    bool IsMinButton() const;
    bool IsTitleBar() const;
    std::wstring GetTitleName() const;
    std::wstring GetActiveEvent() const;
    std::wstring GetCloseEvent() const;
    HBRUSH GetBackBrush() const;
    CMenubar* GetMenu();

    void SetControlBox(bool isControlBox);
    void SetMaxButton(bool isMaxButton);
    void SetMinButton(bool isMinButton);
    void SetTitleBar(bool isTitleBar);
    void SetTitleName(std::wstring title);
    void SetActiveEvent(std::wstring activeEventName);
    void SetCloseEvent(std::wstring closeEventName);
    void SetIcon(std::wstring iconFilePath);
    void SetBackColor(COLORREF backColor);
    void SetMenu(CMenubar* menu);
    void SetParentWindow(CWindowControl *parent);

    /**
     * \brief ������ â�� �����մϴ�.
     */
    void Create() override;

    /**
     * \brief ������ â�� Modal Ÿ������ ��Ÿ���ϴ�.
     * \return setDialogResult �Լ��� ������ ���� ��ȯ�մϴ�.
     */
    int ShowModalWindow();

    /**
     * \brief showModal �Լ��� ��ȯ�ϴ� ���� �����մϴ�.
     * \param value
     */
    void SetDialogResult(int value) const;

    /**
     * \brief ������ Form window �� ������ �Ҹ��ŵ�ϴ�.
     */
    virtual void Destroy() override;

    /**
     * \brief Form �� �����մϴ�.
     */
    void Close() const;

    /**
     * \brief Form �� �ٽ� �׸��ϴ�.
     */
    void Refresh() const;

    static LRESULT CALLBACK OnControlProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    bool _isMaxButton = false;
    bool _isMinButton = true;
    bool _isControlBox = true;
    bool _isTitleBar = true;
    int* _dialogResult = nullptr;
    std::wstring _titleName = L"";
    std::wstring _activeEvent = L"";
    std::wstring _closeEvent = L"";
    HICON _icon = LoadIcon(nullptr, IDI_APPLICATION);
    HBRUSH _backBrush = CreateSolidBrush(GetSysColor(COLOR_3DFACE));
    CMenubar* _menu = nullptr;
};
}
