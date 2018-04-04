require "Script\\control_manager.lua"
require "Script\\listview.lua"

ListViewManager = ControlManager:Instance
{
    CreateListView = function(self, options)
        OUTPUT("-------- Start Create : ListView --------")

        local newControl = nil

        if options ~= nil then
            if options._Control ~= nil then
                return ListView:Instance(options._Control)
            end

            newControl = ListView:New(options.Parent)

            newControl:SetSize(options.Width, options.Height)

            if options.Center then
                local x, y = ControlManager:GetCenterPosition(options.Parent, options.Width, options.Height, true)
                if x ~= nil and y ~= nil then
                    options.X = x
                    options.Y = y
                end
            end
            newControl:Move(options.X, options.Y)

            newControl:SetRowHeight(options.RowHeight)

            if options.Event then
                newControl:SetCreateEvent(options.Event.Create)
                newControl:SetDestroyEvent(options.Event.Destroy)
                newControl:SetMouseLButtonUpEvent(options.Event.MouseLButtonUp)
                newControl:SetMouseLButtonDownEvent(options.Event.MouseLButtonDown)
                newControl:SetMouseMoveEvent(options.Event.MouseMove)
                newControl:SetMouseEnterEvent(options.Event.MouseEnter)
                newControl:SetMouseLeaveEvent(options.Event.MouseLeave)
            end

            if options.Option then
                newControl:SetShowBorder(options.Option.ShowBorder)
                newControl:SetShowColumn(options.Option.ShowColumn)
                newControl:SetSortClickedColumn(options.Option.SortClickedColumn)
                newControl:SetOneClickItemActivated(options.Option.OneClickItemActivated)
                newControl:SetTrackingSelect(options.Option.TrackingSelect)
            end

            newControl:SetUserData(options.UserData)

            newControl:Create()

            if options.Columns then    
                for i = 1, #options.Columns do
                    newControl:AddColumn(options.Columns[i])
                end
            end

            if options.Rows then
                for i = 1, #options.Rows do
                    newControl:AddRow(options.Rows[i])
                end
            end

            if options.Show then
                newControl:Show()
            end
        end

        OUTPUT("-------- End Create : ListView --------")
        return newControl
    end,

    CreateListViewInstance = function(self, control)
        OUTPUT("-------- Create ListView By Instance --------")
        

        local options = {
            _Control = control,
        }

        OUTPUT("-------- End Create ListView By Instance --------")        
        
        return self:CreateListView(options)
    end,

    CreateColumn = function(self, options)
        OUTPUT("-------- Start Create : ListView Column --------")

        local newControl = nil

        if options ~= nil then
            if options._Control ~= nil then
                return ListViewColumn:Instance(options._Control)
            end

            newControl = ListViewColumn:New()

            newControl:SetWidth(options.Width)            

            newControl:SetAutoSizeFitItem(options.AutoSizeFitItem)
            newControl:SetAutoSizeFitHeader(options.AutoSizeFitHeader)

            if options.Text then
                newControl:SetText(options.Text.Content)
                newControl:SetAlign(options.Text.Align)
            end
        end

        OUTPUT("-------- End Create : ListView Column --------")
        return newControl
    end,

    CreateColumnInstance = function(self, control)
        OUTPUT("-------- Create ListView Column By Instance --------")

        local options = {
            _Control = control,
        }

        OUTPUT("-------- End Create ListView Column By Instance --------")        
        
        return self:CreateColumn(options)
    end,

    CreateRow = function(self, options)
        OUTPUT("-------- Start Create : ListView Row --------")

        local newControl = nil

        if options ~= nil then
            if options._Control ~= nil then
                return ListViewRow:Instance(options._Control)
            end

            newControl = ListViewRow:New()            

            newControl:SetEnabled(options.Enabled)

            if options.Event ~= nil then
                newListRow:SetActiveEvent(options.Event.Active)
            end

            if options.Items ~= nil then
                for i = 1, #options.Items do
                    newControl:AddItem(options.Items[i])
                end
            end

            if options.Background ~= nil then
                if options.Background.Color ~= nil then
                    newControl:SetNormalBackgroundColor(options.Background.Color.Normal)
                    newControl:SetFocusedBackgroundColor(options.Background.Color.Focused)
                    newControl:SetDisabledBackgroundColor(options.Background.Color.Disabled)
                    newControl:SetDisableFocusedBackgroundColor(options.Background.Color.DisableFocused)
                end
            end

            if options.Text ~= nil then
                if options.Text.Color ~= nil then
                    newControl:SetNormalTextColor(options.Text.Color.Normal)
                    newControl:SetFocusedTextColor(options.Text.Color.Focused)
                    newControl:SetDisabledTextColor(options.Text.Color.Disabled)
                    newControl:SetDisableFocusedTextColor(options.Text.Color.DisableFocused)
                end
            end                     
        end
		
        OUTPUT("-------- End Create : ListView Row --------")
        return newControl
    end,

    CreateRowInstnace = function(self, control)
        OUTPUT("-------- Create ListView Row By Instance --------")

        local options = {
            _Control = control,
        }

        OUTPUT("-------- End Create ListView Row By Instance --------")        
        
        return self:CreateRow(options)
    end,

    CreateItem = function(self, options)
        OUTPUT("-------- Start Create : ListView Item --------")

        local newControl = nil

        if options ~= nil then
            if options._Control ~= nil then
                return ListViewItem:Instance(options._Control)
            end

            newControl = ListViewItem:New()

            if options.Background ~= nil then
                if options.Background.Color ~= nil then
                    newControl:SetNormalBackgroundColor(options.Background.Color.Normal)
                    newControl:SetFocusedBackgroundColor(options.Background.Color.Focused)
                    newControl:SetDisabledBackgroundColor(options.Background.Color.Disabled)
                    newControl:SetDisableFocusedBackgroundColor(options.Background.Color.DisableFocused)
                end
            end

            if options.Text ~= nil then
                if options.Text.Font ~= nil then
                    newControl:SetFontName(options.Text.Font.Name)
                    newControl:SetFontSize(options.Text.Font.Size)
                    newControl:SetBold(options.Text.Font.Bold)
                    newControl:SetUnderline(options.Text.Font.Underline)
                    newControl:SetItalic(options.Text.Font.Italic)
                end

                newControl:SetAlign(options.Text.Align)
                newControl:SetText(options.Text.Content)
                if options.Text.Color ~= nil then
                    newControl:SetNormalTextColor(options.Text.Color.Normal)
                    newControl:SetFocusedTextColor(options.Text.Color.Focused)
                    newControl:SetDisabledTextColor(options.Text.Color.Disabled)
                    newControl:SetDisableFocusedTextColor(options.Text.Color.DisableFocused)
                end
            end      
        end
		
        OUTPUT("-------- End Create : ListView Item --------")
        return newControl
    end,
}