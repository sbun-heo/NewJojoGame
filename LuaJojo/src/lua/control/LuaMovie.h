﻿#pragma once

#include "LuaControl.h"

namespace jojogame {
class LuaForm;

class __declspec(dllexport) LuaMovie : public LuaControl
{
public:
    explicit LuaMovie(LuaForm *parent);
    virtual ~LuaMovie();

    WNDPROC oldProc();

    void play();
    void stop();

    void create(std::wstring fileName);
    void destroy() override;

    static void registerToLua();
private:
    WNDPROC _oldProc;
};
}
