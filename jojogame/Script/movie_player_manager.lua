require "Script\\control_manager.lua"
require "Script\\movie_player.lua"

MoviePlayerManager = ControlManager:Instance
{
    Create = function(options)
        local newMoviePlayer = MoviePlayer:Instance(options.Parent, options.FileName)

        newMoviePlayer:SetClickEvent(options.ClickEvent)
        newMoviePlayer:Create()

        local width, height = newMoviePlayer:Size()
        if options.Center then
            local x, y = ControlManager.GetCenterPosition(options.Parent, width, height)
            if x ~= nil and y ~= nil then
                options.X = x
                options.Y = y
            end
        end
        newMoviePlayer:Move(options.X, options.Y)
        
        return newMoviePlayer
    end,
}