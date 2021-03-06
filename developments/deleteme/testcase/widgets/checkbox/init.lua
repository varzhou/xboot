local CheckBox = require "xboot.widget.CheckBox"
local Pattern = Pattern

local M = Class(DisplayObject)

function M:init(w, h)
	self.super:init(w, h)

	local assets = assets

	self:addChild(DisplayShape.new(w, h)
		:setSource(Pattern.image(assets:loadImage("widgets/checkbox/bg.png")):setExtend("repeat"))
		:paint())

	local checkbox = CheckBox.new({x = 100, y = 100})
		:addEventListener("change", function(d, e) print("CheckBox changed:", e.checked) end)
	self:addChild(checkbox)
end

return M
