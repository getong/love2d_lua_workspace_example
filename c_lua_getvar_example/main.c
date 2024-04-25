#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>

void lua_example_dofile(void) {
  lua_State *L = luaL_newstate();

  luaL_openlibs(L);
  luaL_dofile(L, "factorial.lua");
  lua_close(L);
}

void lua_example_getvar(void) {
  lua_State *L = luaL_newstate();
  luaL_dostring(L, "some_var = 486");
  lua_getglobal(L, "some_var");
  lua_Number some_var_in_c = lua_tonumber(L, -1);

  printf("The value of some_var inside c is %d\n", (int)some_var_in_c);
  lua_close(L);
}

int main(int argc, char *argv[]) {

  lua_example_getvar();
  return 0;
}

// ./build.sh
// ./build/c_lua_getvar