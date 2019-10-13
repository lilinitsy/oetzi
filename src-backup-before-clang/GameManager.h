#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>

#include "Model.h"
#include "Octree.h"


// Don't allocate for individual gameobjects, but it makes sense for model data

struct GameManager
{
	std::vector<std::string> names;
	std::vector<glm::vec3> positions;
	std::vector<Model*> models;
	std::vector<AABB> aabbs;
	Octree *octree;
	int num_gameobjects;

	void update();
};

#endif