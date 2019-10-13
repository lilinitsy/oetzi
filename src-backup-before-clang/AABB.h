#ifndef AABBH_H
#define AABBH_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


struct AABB
{
	glm::vec3 position;
	glm::vec3 extents;
};

bool AABB_overlap(AABB *a, AABB *b);

#endif