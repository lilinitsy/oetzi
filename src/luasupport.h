#ifndef LUASUPPORT_H
#define LUASUPPORT_H

#include "GPU-Includes.h"

//LUA includes
extern "C" {
    #include <external/Lua/src/lua.h>
    #include <external/Lua/src/lauxlib.h>
    #include <external/Lua/src/lualib.h>
}

void luaSetup(lua_State * L);

//TODO: Maybe move related lua functions to the .h/.cpp files that provide them
//      e.g. move laodAudio, playSound, and playSoundEffect lua calls to Audiomanager

int add_model(lua_State * L); //Adds model to be drawn
int findModel(lua_State * L); //Find model ID based on name
int getChild(lua_State * L); //Find a child model (pre-fab) with a given name

int scaleModel(lua_State * L);

int placeModel(lua_State * L);
int placeModelAtAngle(lua_State * L);
int translateModel(lua_State * L);
int rotateModel(lua_State * L);
int resetTransformation(lua_State * L);


glm::vec3 getCameraPosFromLau(lua_State * L);
glm::vec3 getCameraDirFromLau(lua_State * L);
glm::vec3 getCameraUpFromLau(lua_State * L);

#endif //LUASUPPORT_H