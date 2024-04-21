function getHalf(i)
   local var = i
   var = var / 2
   return var
end

message = 20

chicken = getHalf(message)

function love.draw()
   love.graphics.setFont(love.graphics.newFont(50))
   love.graphics.print("message is " .. message .. " chicken is " .. chicken)
end
