require "Script\\control_manager.lua"
require "Script\\movie_player.lua"

MoviePlayerManager = ControlManager:Instance
{
    Create = function(self, options)
        OUTPUT("-------- Start Create : Movie Player --------")

        local newControl = nil
        
        if options ~= nil then
            newControl = MoviePlayer:New(options.Parent, options.FileName)

            if options.Event then
                newControl:SetEndEvent(options.Event.End)
            end

            newControl:Move(options.X, options.Y)
            newControl:Create()

            if options.Center then
                local movieWidth, movieHeight = newControl:Size()
                if options.Parent then
                    local parentWidth, parentHeight = options.Parent:Size()
                    newControl:Move(parentWidth / 2 - movieWidth / 2, parentHeight / 2 - movieHeight / 2)
                end
            end
        end

        OUTPUT("-------- End Create : Movie Player --------")

        return newControl
    end,
}