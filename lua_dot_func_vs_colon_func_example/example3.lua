obj = {}
obj.func = function(a, b, c)
   print(a, b, c)
end

mtable = { __index = obj }
otherobj = {}

setmetatable(otherobj, mtable)

print("obj:", obj)
print("mtable", mtable)
print("otherobj:", otherobj)

otherobj.func(1, 2)
otherobj:func(1, 2)

-- obj:    table: 0x60000283c840
-- mtable  table: 0x60000283c880
-- otherobj:       table: 0x60000283c940
-- 1       2       nil
-- table: 0x60000283c940   1       2

-- lua example3.lua
-- copy from https://www.cnblogs.com/lzpong/p/13426782.html
