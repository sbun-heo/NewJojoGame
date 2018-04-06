require "Script\\object.lua"

ControlObject = Object:Instance
{
    control = nil,
}

Control = ControlObject:Instance
{
    Create = function(self)
        OUTPUT("Try Create")
        result = self.control:Create()
        if result then
            OUTPUT("Success create")
        else
            OUTPUT("Fail to create")
        end
    end,

    Destroy = function(self)
        self.control:Destroy()
        OUTPUT("Destroy")
    end,

    Move = function(self, x, y)
        if x ~= nil then
            self.control:SetX(x)
        end
        if y ~= nil then
            self.control:SetY(y)
        end

        OUTPUT("Move (" .. (x or "NOT MOVE") .. ", " .. (y or "NOT MOVE") .. ")")        
    end,

    SetSize = function(self, w, h)
        if w ~= nil then
            self.control:SetWidth(w)
            OUTPUT("Set Width " .. w)        
        end
        if h ~= nil then
            self.control:SetHeight(h)
            OUTPUT("Set Height " .. h)                    
        end
    end,
    
    Show = function(self)
        self.control:Show()

        OUTPUT("Show")                
    end,

    Hide = function(self)
        self.control:Hide()
        OUTPUT("Hide")
    end,

    Position = function(self)
        OUTPUT("Get Position (" .. self.control:GetX() .. ", " .. self.control:GetY() .. ")")
        
        return self.control:GetX(), self.control:GetY()
    end,

    Width = function(self)
        OUTPUT("Get Width " .. self.control:GetWidth())
        return self.control:GetWidth()
    end,

    Height = function(self)
        OUTPUT("Get Height " .. self.control:GetHeight())
        return self.control:GetHeight()
    end,

    Size = function(self)
        OUTPUT("Get Size (" .. self.control:GetWidth() .. ", " .. self.control:GetHeight() .. ")")
        return self.control:GetWidth(), self.control:GetHeight()
    end,

    UserData = function(self)
        return self.control:GetUserData()
    end,

    SetCreateEvent = function(self, event)
        if event ~= nil then
            self.control:SetCreateEvent(event)

            OUTPUT("Set Create Event" )
        end
    end,

    SetDestroyEvent = function(self, event)
        if event ~= nil then            
            self.control:SetDestroyEvent(event)

            OUTPUT("Set Destroy Event")
        end
    end,

    SetMouseLButtonUpEvent = function(self, event)
        if event ~= nil then
            self.control:SetMouseLButtonUpEvent(event)

            OUTPUT("Set MouseLButtonUp Event")
        end
    end,

    SetMouseLButtonDownEvent = function(self, event)
        if event ~= nil then
            self.control:SetMouseLButtonDownEvent(event)
            
            OUTPUT("Set MouseLButtonDown Event")
        end
    end,

    SetMouseMoveEvent = function(self, event)
        if event ~= nil then
            self.control:SetMouseMoveEvent(event)

            OUTPUT("Set MouseMove Event")
        end
    end,

    SetMouseEnterEvent = function(self, event)
        if event ~= nil then        
            self.control:SetMouseEnterEvent(event)

            OUTPUT("Set MouseEnter Event")
        end
    end,

    SetMouseLeaveEvent = function(self, event)
        if event ~= nil then
            self.control:SetMouseLeaveEvent(event)

            OUTPUT("Set MouseLeave Event")
        end
    end,

    SetUserData = function(self, data)
        if data ~= nil then
            self.control:SetUserData(data)

            OUTPUT("Set User Data : " .. data)
        end
    end,

    Refresh = function(self)
        self.control:Refresh()
    end,

    RefreshRegion = function(self, rect)
        if rect ~= nil then
            self.control:RefreshRegion(rect.Left, rect.Top, rect.Right, rect.Bottom)
        end
    end,
}