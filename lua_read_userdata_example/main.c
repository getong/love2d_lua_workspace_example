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

void lua_example_stack(void) {
  lua_State *L = luaL_newstate();
  lua_pushnumber(L, 286); // stack[1] or stack[-3]
  lua_pushnumber(L, 386); // stack[2] or stack[-2]
  lua_pushnumber(L, 486); // stack[3] or stack[-1]

  lua_Number element;
  element = lua_tonumber(L, -1);

  printf("The last added element in position 3 of the stack is %d\n",
         (int)element);
  lua_remove(L, 2); // this should remove 386 from the stack
  element = lua_tonumber(L, 2);
  printf("Position 2 of the stack is now: %d\n", (int)element);
  lua_close(L);
}

void lua_example_call_lua_function(void) {
  lua_State *L = luaL_newstate();
  if (luaL_dofile(L, "pythagoras.lua") != LUA_OK) {
    luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
  }

  lua_getglobal(L, "pythagoras");
  if (lua_isfunction(L, -1)) {
    lua_pushnumber(L, 3); // 1st function argument, a
    lua_pushnumber(L, 4); // 2nd function argument, b
    const int NUM_ARGS = 2;
    const int NUM_RETURNS = 1;
    if (lua_pcall(L, NUM_ARGS, NUM_RETURNS, 0) != LUA_OK) {
      // TODO:... error
    } else {
      lua_Number pythagoras_result = lua_tonumber(L, -1);
      printf("The Pythagors(3, 4) is %f\n", (float)pythagoras_result);
    }
  }

  lua_close(L);
}

int native_pythagoras(lua_State *L) {
  lua_Number b = lua_tonumber(L, -1); // get the 1ast added paramet3er
  lua_Number a = lua_tonumber(L, -2); // get the first added paramet3er
  lua_Number result = (a * a) + (b * b);
  lua_pushnumber(L, result);
  return 1;
}

void lua_example_call_c_function(void) {
  lua_State *L = luaL_newstate();
  lua_pushcfunction(L, native_pythagoras);
  lua_setglobal(L, "native_pythagoras");

  luaL_dofile(L, "pythagoras-native.lua");
  lua_getglobal(L, "pythagoras");

  if (lua_isfunction(L, -1)) {
    lua_pushnumber(L, 3); // 1st function argument, a
    lua_pushnumber(L, 4); // 2nd function argument, b

    const int NUM_ARGS = 2;
    const int NUM_RETURNS = 1;
    if (lua_pcall(L, NUM_ARGS, NUM_RETURNS, 0) != LUA_OK) {
      // TODO:... error
    } else {
      lua_Number pythagoras_result = lua_tonumber(L, -1);
      printf("Native Pythagors(3, 4) is %f\n", (float)pythagoras_result);
    }
  }

  lua_close(L);
}

typedef struct rectangle2d {
  int x;
  int y;
  int width;
  int height;
} rectangle;

int create_rectangle(lua_State *L) {
  rectangle *rect = (rectangle *)lua_newuserdata(L, sizeof(rectangle));
  rect->x = 0;
  rect->y = 0;
  rect->width = 0;
  rect->height = 0;
  return 1;
}

int change_rectangle_size(lua_State *L) {
  rectangle *rect = (rectangle *)lua_touserdata(L, -3);
  rect->width = (int)lua_tonumber(L, -2);
  rect->height = (int)lua_tonumber(L, -1);
  return 0;
}

void lua_example_userdata(void) {
  lua_State *L = luaL_newstate();

  lua_pushcfunction(L, create_rectangle);
  lua_setglobal(L, "create_rectangle");

  lua_pushcfunction(L, change_rectangle_size);
  lua_setglobal(L, "change_rectangle_size");

  luaL_dofile(L, "rectangle.lua");

  lua_getglobal(L, "square");
  if (lua_isuserdata(L, -1)) {
    rectangle *r = (rectangle *)lua_touserdata(L, -1);
    printf("We got back a rectangle from Lua, width: %d, height: %d.\n",
           r->width, r->height);
  } else {
    printf("We did not get a rectangle userdata from Lua.");
  }
  lua_close(L);
}

void lua_example_table(void) {
  lua_State *L = luaL_newstate();
  if (luaL_dofile(L, "configtable.lua") == LUA_OK) {
    lua_getglobal(L, "config_table");
    if (lua_istable(L, -1)) {
      lua_getfield(L, -1, "window_width");
      printf("The window width defined in the Lua table is %s\n",
             lua_tostring(L, -1));
    } else {
      luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }
  }
}

int main(int argc, char *argv[]) {

  /* lua_example_stack(); */
  /* lua_example_call_lua_function(); */
  /* lua_example_call_c_function(); */
  /* lua_example_call_c_function(); */
  /* lua_example_userdata(); */
  lua_example_table();
  return 0;
}

// ./build.sh
// ./build/lua_call_c_function