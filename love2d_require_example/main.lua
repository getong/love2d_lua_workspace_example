-- Incorrect way, will cause an error, but for demonstration:
local a = require("math")

message = a.random(200, 300)

function increaseMessage(i)
   message = message + i
end

function double(val)
   val = val * 2
   return val
end

increaseMessage(30)
increaseMessage(5)

chicken = double(message)

function love.draw()
   love.graphics.setFont(love.graphics.newFont(50))
   love.graphics.print("message is " .. message .. " chicken is " .. chicken)
end
