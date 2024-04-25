// filename:funct.c

#define LUA_LIB
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

static int _c_l_testfunc(lua_State *L) {
  unsigned char argc, index;
  const char *typename;
  if ((argc = lua_gettop(L)) != 0) {
    printf("共传入 %d 个参数\n", argc);
    for (index = 1; index <= argc; index++) {
      printf("第 %d 个参数类型为: %s\n", index,
             lua_typename(L, lua_type(L, index)));
    }
  } else {
    puts("0 个参数传入");
  }

  // 清空栈
  lua_settop(L, 0);

  // 把参数个数压入栈作为返回值
  lua_pushinteger(L, argc);

  return 1;
}

#ifdef __cplusplus
#define EXP_FUNC __declspec(dllexport)
#else
#define EXP_FUNC
#endif

LUA_API EXP_FUNC int luaopen_funct(lua_State *L) {
  lua_pushcfunction(L, _c_l_testfunc);
  return 1;
}

// mkdir -p build
// gcc funct.c -I/usr/local/include/lua -llua -shared -o build/funct.so

// copy from https://www.cnblogs.com/lzpong/p/13426782.html
// modified by chatgpt