require "Script\\control.lua"

MoviePlayer = ControlObject:Instance
{
    New = function(self, parent, fileName)
        local newControl = {}
        local parentControl = nil

        if parent ~= nil then
            parentControl = parent.control
        end
        if fileName == nil then
            fileName = ""
        end

        newControl.control = controlManager:CreateMoviePlayer(parentControl, fileName)
        setmetatable(newControl, self)
        self.__index = self
        
        return newControl
    end,

    Create = function(self)
        self.control:Create()

        OUTPUT("Movie Created")
    end,
    
    Destroy = function(self)
        self.control:Destroy()

        OUTPUT("Movie Destroy")
    end,

    Play = function(self)
        OUTPUT("Movie Play")
        
        self.control:Play()
    end,

    Stop = function(self)
        OUTPUT("Movie Stop")
        
        self.control:Stop()
    end,

    IsPlaying = function(self)
        return self.control:IsPlaying()
    end,
    
    Size = function(self)
        return self.control:GetWidth(), self.control:GetHeight()
    end,

    SetEndEvent = function(self, event)
        self.control:SetEndEvent(event)

        OUTPUT("Set End Event")
    end,

    Move = function(self, x, y)
        if x ~= nil then
            self.control:SetX(x)
        end

        if y ~= nil then
            self.control:SetY(y)
        end
    end,
    
}