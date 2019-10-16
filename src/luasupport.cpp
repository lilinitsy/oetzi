#include "luasupport.h"
#include <algorithm>

#include <external/loguru.hpp>

#include "Model.h"

#pragma GCC diagnostic ignored "-Wunused-variable" //TODO: Delete this line, this is hacky =/

void luaSetup(lua_State* L)
{
	//open all libraries
	luaL_openlibs(L);

	//register new custom method
	lua_register(L, "placeModel", placeModel);
	lua_register(L, "add_model", add_model);
	lua_register(L, "findModel", findModel);
	lua_register(L, "rotateModel", rotateModel);
	lua_register(L, "scaleModel", scaleModel);
	lua_register(L, "translateModel", translateModel);
	lua_register(L, "resetTransformation", resetTransformation);
}

//----------- Camera ----------

glm::vec3 getCameraPosFromLau(lua_State* L)
{
	glm::vec3 cameraPos;
	int argc = lua_gettop(L);
	lua_getglobal(L, "CameraPosX");
	cameraPos.x = (float)lua_tonumber(L, 1);
	lua_getglobal(L, "CameraPosY");
	cameraPos.y = (float)lua_tonumber(L, 2);
	lua_getglobal(L, "CameraPosZ");
	cameraPos.z = (float)lua_tonumber(L, 3);
	lua_pop(L, 3);
	return cameraPos;
}

glm::vec3 getCameraDirFromLau(lua_State* L)
{
	glm::vec3 cameraDir;
	int argc = lua_gettop(L);
	lua_getglobal(L, "CameraDirX");
	cameraDir.x = (float)lua_tonumber(L, 1);
	lua_getglobal(L, "CameraDirY");
	cameraDir.y = (float)lua_tonumber(L, 2);
	lua_getglobal(L, "CameraDirZ");
	cameraDir.z = (float)lua_tonumber(L, 3);
	lua_pop(L, 3);
	return cameraDir;
}

glm::vec3 getCameraUpFromLau(lua_State* L)
{
	glm::vec3 cameraUp;
	int argc = lua_gettop(L);
	lua_getglobal(L, "CameraUpX");
	cameraUp.x = (float)lua_tonumber(L, 1);
	lua_getglobal(L, "CameraUpY");
	cameraUp.y = (float)lua_tonumber(L, 2);
	lua_getglobal(L, "CameraUpZ");
	cameraUp.z = (float)lua_tonumber(L, 3);
	lua_pop(L, 3);
	return cameraUp;
}

// -----------Model Loading ------------
#include <string>
using std::string;
using std::swap; //fast delete
using std::vector;

vector<Model*> modelPool;

int add_model(lua_State* L)
{
	static int luaModelCount = 0;

	const char* rawModelName;
	float tx, ty, tz;
	int argc = lua_gettop(L);
	rawModelName = lua_tostring(L, 1);
	tx = lua_tonumber(L, 2);
	ty = lua_tonumber(L, 3);
	tz = lua_tonumber(L, 4);
	LOG_F(1, "Adding model %s at (%f, %f, %f)", rawModelName, tx, ty, tz);

	string child_modelsName(rawModelName);

	int myModelID;
	Model* pooledModel = 0;
	for(auto it = modelPool.begin(); it < modelPool.end(); it++)
	{ //TODO: This is slow, maybe we should hash the row model name to an address somehow?
		if((*it)->child_models.size() == 1 && (*it)->child_models[0]->name == child_modelsName)
		{
			pooledModel = *it;
			myModelID = (*it)->id;
			swap(*it, modelPool.back());
			modelPool.pop_back();
			//printf("Found model id %d (%d available) with only child named: %s",myModelID,modelPool.size(),child_modelsName.c_str());
			//TODO: We should ideally reset his material, etc... (not just transformation)
			global_model_list[myModelID].transform = glm::translate(glm::mat4(), glm::vec3(tx, ty, tz));
			break;
		}
	}

	if(!pooledModel)
	{
		//printf("No pooled %s resource found (%d available), adding model",child_modelsName.c_str(),modelPool.size());
		string modelName = child_modelsName + std::to_string(luaModelCount);
		luaModelCount++;
		myModelID = add_model(modelName);
		add_child(child_modelsName, myModelID);
		global_model_list[myModelID].transform = glm::translate(global_model_list[myModelID].transform, glm::vec3(tx, ty, tz));
	}

	lua_pushnumber(L, myModelID);

	return 1;
}

int findModel(lua_State* L)
{
	int modelID = -1;
	string modelName;
	int argc = lua_gettop(L);
	modelName = lua_tostring(L, 1);
	for(int i = 0; i < num_models; i++)
	{
		if(global_model_list[i].name == modelName)
		{
			modelID = i;
			continue;
		}
	}
	if(modelID == -1)
	{
		LOG_F(WARNING, "ERROR: Model '%s' not found!", modelName.c_str());
		return 0; //Returns 'nil' to script
	}

	LOG_F(INFO, "Found Model '%s' at Node: %d", global_model_list[modelID].name.c_str(), modelID);

	lua_pushinteger(L, modelID);

	return 1;
}

int getChild(lua_State* L)
{
	int parentModelID, childNumber, child_modelsID;
	string childName;
	int argc = lua_gettop(L);
	parentModelID = (int)lua_tonumber(L, 1);
	childNumber = (int)lua_tonumber(L, 2);
	LOG_F(INFO, "Finding Child: %d of %d children", childNumber, (int)global_model_list[parentModelID].child_models[0]->child_models.size());
	childName = global_model_list[parentModelID].child_models[0]->child_models[childNumber]->name;
	for(int i = 0; i < num_models; i++)
	{
		if(global_model_list[i].name == childName)
		{
			child_modelsID = i;
			continue;
		}
	}
	LOG_F(INFO, "Node %s child #%d is %s", global_model_list[parentModelID].name.c_str(), childNumber, global_model_list[child_modelsID].name.c_str());

	return 1;
}

//TODO: Placing a model undoes its rotation/scale, we should probably fix this
int placeModel(lua_State* L)
{
	int modelID = -1;
	float tx, ty, tz;
	int argc = lua_gettop(L);
	modelID = lua_tonumber(L, 1);
	tx = lua_tonumber(L, 2);
	ty = lua_tonumber(L, 3);
	tz = lua_tonumber(L, 4);
	LOG_F(1, "Placing model %s at (%f, %f, %f)", global_model_list[modelID].name.c_str(), tx, ty, tz);

	global_model_list[modelID].transform = glm::translate(glm::mat4(), glm::vec3(tx, ty, tz));

	return 0;
}

//Give a position and rotation
int placeModelAtAngle(lua_State* L)
{
	int modelID = -1;
	float tx, ty, tz;
	float ang, rx, ry, rz;
	int argc = lua_gettop(L);
	modelID = lua_tonumber(L, 1);
	tx = lua_tonumber(L, 2);
	ty = lua_tonumber(L, 3);
	tz = lua_tonumber(L, 4);
	ang = lua_tonumber(L, 5);
	rx = lua_tonumber(L, 6);
	ry = lua_tonumber(L, 7);
	rz = lua_tonumber(L, 8);
	LOG_F(1, "Placing model %s at (%f, %f, %f)", global_model_list[modelID].name.c_str(), tx, ty, tz);

	global_model_list[modelID].transform = glm::translate(glm::mat4(), glm::vec3(tx, ty, tz));
	global_model_list[modelID].transform = glm::rotate(global_model_list[modelID].transform, ang, glm::vec3(rx, ry, rz));

	return 0;
}

//TODO: This assumes you will translate after rotating, is that safe?
int translateModel(lua_State* L)
{
	int modelID = -1;
	float tx, ty, tz;
	int argc = lua_gettop(L);
	modelID = lua_tonumber(L, 1);
	tx = lua_tonumber(L, 2);
	ty = lua_tonumber(L, 3);
	tz = lua_tonumber(L, 4);
	LOG_F(1, "Translating model %s at (%f, %f, %f)", global_model_list[modelID].name.c_str(), tx, ty, tz);

	glm::mat4 tmat = glm::translate(glm::mat4(), glm::vec3(tx, ty, tz));
	global_model_list[modelID].transform = tmat * global_model_list[modelID].transform;

	return 0;
}

int scaleModel(lua_State* L)
{
	int modelID = -1;
	float sx, sy, sz;
	int argc = lua_gettop(L);
	modelID = lua_tonumber(L, 1);
	sx = lua_tonumber(L, 2);
	sy = lua_tonumber(L, 3);
	sz = lua_tonumber(L, 4);
	LOG_F(1, "Scaling model %s at (%f, %f, %f)", global_model_list[modelID].name.c_str(), sx, sy, sz);

	global_model_list[modelID].transform = glm::scale(global_model_list[modelID].transform, glm::vec3(sx, sy, sz));

	return 0;
}

int rotateModel(lua_State* L)
{
	int modelID = -1;
	float ang, rx, ry, rz;
	int argc = lua_gettop(L);
	modelID = lua_tonumber(L, 1);
	ang = lua_tonumber(L, 2);
	rx = lua_tonumber(L, 3);
	ry = lua_tonumber(L, 4);
	rz = lua_tonumber(L, 5);
	LOG_F(1, "Rotating model %s at by angle %f along (%f, %f, %f)", global_model_list[modelID].name.c_str(), ang, rx, ry, rz);

	//printf("# Children: %d",global_model_list[modelID].numChildren;);

	global_model_list[modelID].transform = glm::rotate(global_model_list[modelID].transform, ang, glm::vec3(rx, ry, rz));

	return 0;
}

int resetTransformation(lua_State* L)
{
	int modelID = -1;
	float ang, rx, ry, rz;
	int argc = lua_gettop(L);
	modelID = lua_tonumber(L, 1);
	ang = lua_tonumber(L, 2);
	rx = lua_tonumber(L, 3);
	ry = lua_tonumber(L, 4);
	rz = lua_tonumber(L, 5);
	LOG_F(1, "Resetting model %s transform to Identity )", global_model_list[modelID].name.c_str());

	global_model_list[modelID].transform = glm::mat4();

	return 0;
}