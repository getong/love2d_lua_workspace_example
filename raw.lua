--file: raw.lua
datas = {}
datas.mt = {}

function datas.new(o)
   o = o or {}
   setmetatable(o, datas.mt)
   return o
end

datas.mt.__index = function(t, k)
   return 'default'
end

datas.mt.__newindex = function(t, k, v)
   if k == "test" then
      rawset(t, "test", "value")
   end
end

d = datas.new()

--查询table d 中不存在的元素 x 时，会调用__index指向的函数
print(d.x) -->defaule

--调用了rawget(t,k,v)，绕过了元表的__index和__newindex，因为table d为空表，所以返回nil
print(rawget(d, d.test)) -->nil

--为table d中不存在的元素 test 赋值，调用元表对应的__newindex，参数" t = d , k = test , v = nil"
--元表中的__newindex对应的函数调用rawset，绕过元表，直接为table d  赋值，此时d["test"] = "vale"
d.test = "something"

--table d中“test”对应的值为“value”
print(d.test) --value

--table d中“test”对应的值为“value”
print(rawget(d, "test")) --value

-- lua raw.lua
-- copy from https://www.cnblogs.com/sylvan/p/8478366.html