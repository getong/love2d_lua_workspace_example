message = "lua is awesome!!"

function love.draw()
   love.graphics.setFont(love.graphics.newFont(50))
   love.graphics.print(message)
end