#pragma once

#include "LuaControl.h"

#include <string>

namespace jojogame {
class LuaMenubar;

class __declspec(dllexport) LuaForm : public LuaControl
{
public:
    explicit LuaForm(bool popup);
    virtual ~LuaForm();

    LuaForm(const LuaForm&) = delete;
    LuaForm& operator=(const LuaForm&) = delete;

    bool controlBox() const;
    bool maxButton() const;
    bool minButton() const;
    std::wstring titleName() const;
    bool titleBar() const;
    std::wstring activeFunction() const;
    std::wstring closeFunction() const;
    HBRUSH backBrush() const;
    LuaMenubar* menu();

    void setControlBox(bool controlBox);
    void setMaxButton(bool maxButton);
    void setMinButton(bool minButton);
    void setTitleName(std::wstring title);
    void setTitleBar(bool titleBar);
    void setActiveFunction(std::wstring activeFunction);
    void setCloseFunction(std::wstring closeFunction);
    void setIcon(std::wstring iconFilePath);
    void setBackColor(COLORREF backColor);
    void setMenu(LuaMenubar* menu);

    /**
     * \brief Form window �� �����մϴ�.
     */
    void create();

    /**
     * \brief �θ� Form �� ���ӵǾ� ����� ������ �θ� Form �� ������ �����ϴ� Form window �� �����մϴ�.
     * \param parentForm ���ӵ� �θ� Form control
     */
    void createModal(LuaForm& parentForm);

    /**
     * \brief createModal �Լ��� ���� ������ window �� ��Ÿ���ϴ�.
     * \return setDialogResult �Լ��� ������ ���� ��ȯ�մϴ�.
     */
    int showModal();

    /**
     * \brief showModal �Լ��� ��ȯ�ϴ� ���� �����մϴ�.
     * \param value
     */
    void setDialogResult(int value) const;

    /**
     * \brief ������ Form window �� ������ �Ҹ��ŵ�ϴ�.
     */
    virtual void destroy() override;

    /**
     * \brief Form �� �����մϴ�.
     */
    void close() const;

    /**
     * \brief Form �� �ٽ� �׸��ϴ�.
     */
    void refresh() const;

    static void registerToLua();
private:
    bool _maxButton = false;
    bool _minButton = true;
    bool _controlBox = true;
    bool _titleBar = true;
    int* _dialogResult = nullptr;
    std::wstring _titleName = L"";
    std::wstring _activeFunction = L"";
    std::wstring _closeFunction = L"";
    HICON _icon = LoadIcon(nullptr, IDI_APPLICATION);
    HBRUSH _backBrush = CreateSolidBrush(GetSysColor(COLOR_3DFACE));
    LuaMenubar* _menu;
};
}
