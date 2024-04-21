testScores = {}

testScores[1] = 95
testScores[2] = 87
testScores[3] = 98

message = testScores[2]

table.insert(testScores, 101)
table.insert(testScores, 102)
table.insert(testScores, 103)

message2 = testScores[5]

testScores["math"] = 91
message3 = testScores["math"]
message4 = testScores.math

testScores2 = { 95, 87, 98 }

testScores2.subject = "science"

message5 = 0
message6 = testScores2["subject"]

for i, s in ipairs(testScores2) do
   message5 = message5 + s
end


function love.draw()
   love.graphics.setFont(love.graphics.newFont(50))
   love.graphics.print("message is " ..
      message ..
      "\nmessage2 is " ..
      message2 ..
      "\nmessage3 is " ..
      message3 .. "\nmessage4 is " .. message4 .. "\nmessage5 is " .. message5 .. "\nmessage6 is " .. message6)
end
