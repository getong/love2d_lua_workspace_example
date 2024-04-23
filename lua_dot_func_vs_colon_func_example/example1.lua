-- example1.lua
--定义一张表obj
obj = {}
--下面的这行代码等价于obj["func"]=function(a,b,c)...
obj.func = function(a, b, c)
   print(a, b, c)
end

print("obj:", obj)
obj.func(1, 2)
obj:func(1, 2)

-- lua example1.lua
-- copy from https://www.cnblogs.com/lzpong/p/13426782.html