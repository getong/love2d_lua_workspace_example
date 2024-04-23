package.cpath = package.cpath .. ";build/liblua_funct.so"

funct = require("liblua_funct")

--建一个表来存这个函数
obj = {}
obj.func = funct

print("\".\"调用:")
obj.func(1, "str")
print("\":\"调用:")
obj:func(1, "str")


-- mkdir -p build
-- gcc funct.c -I/usr/local/include/lua -llua -shared -o build/liblua_funct.so
-- lua example4.lua
-- copy from https://www.cnblogs.com/lzpong/p/13426782.html
