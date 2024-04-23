--下面这种定义表中函数的当大相信大家都不陌生
obj = {}
function obj:func(a, b, c)
   print(a, b, c)
end

print("obj:", obj)
obj.func(1, 2)
obj:func(1, 2)

-- lua example2.lua
-- copy from https://www.cnblogs.com/lzpong/p/13426782.html
