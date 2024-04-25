#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  lua_State *L = luaL_newstate();

  luaL_openlibs(L);
  luaL_dofile(L, "factorial.lua");
  lua_close(L);

  return 0;
}

// ./build/c_call_lua