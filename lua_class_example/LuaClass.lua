--file:LuaClass.lua
--声明Lua类，这里声明了类名还有属性，并且给出了属性的初始值。
LuaClass = {x = 0, y = 0}

--定义LuaClass的元表的__index索引为自身，仅在自身上查相应属性
LuaClass.__index = LuaClass

--构造函数New()
--如果在声明时使用了冒号，而在调用时使用点来调用，则会报错：找不到名为self的定义以及变量
function LuaClass:New(x, y)
local temp = {};    --构造临时表，如果没有这句，那么类所建立的对象改变，其他对象都会改变
    setmetatable(temp, LuaClass);  --将临时表temp的元表metatable设定为LuaClass
    self.x = x;
    self.y = y;
    return temp;    --返回自身
end

--测试打印方法--
function LuaClass:Test()
    print("x: " .. self.x .. " y: " .. self.y);
end
