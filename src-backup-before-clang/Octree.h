#ifndef OCTREE_H
#define OCTREE_H

#include <vector>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

#include "AABB.h"

/*
	There's an issue with this that I haven't tracked down yet. 
*/

struct Octree
{
	Octree *children[8];
	std::vector<AABB> objects;
	glm::vec3 position;
	glm::vec3 half_dimension;
	bool is_leaf = true;

	Octree();
	Octree(glm::vec3 p, glm::vec3 hd);
	void insert(AABB object);
	Octree octree_containing_point(glm::vec3 point);
	int get_octant_containing_point(glm::vec3 point);
	void to_string();
};

bool operator==(Octree o1, Octree o2);
bool operator!=(Octree o1, Octree o2);


#endif