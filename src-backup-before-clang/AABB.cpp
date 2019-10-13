#include "AABB.h"

bool AABB_overlap(AABB *a, AABB *b)
{
	float a_x_min = a->position.x - a->extents.x;
	float a_x_max = a->position.x + a->extents.x;
	float a_y_min = a->position.y - a->extents.y;
	float a_y_max = a->position.y + a->extents.y;
	float a_z_min = a->position.z - a->extents.z;
	float a_z_max = a->position.z + a->extents.z;

	float b_x_min = b->position.x - b->extents.x;
	float b_x_max = b->position.x + b->extents.x;
	float b_y_min = b->position.y - b->extents.y;
	float b_y_max = b->position.y + b->extents.y;
	float b_z_min = b->position.z - b->extents.z;
	float b_z_max = b->position.z + b->extents.z;

	bool x_overlap = a_x_min <= b_x_max && a_x_max >= b_x_min;
	bool y_overlap = a_y_min <= b_y_max && a_y_max >= b_y_min;
	bool z_overlap = a_z_min <= b_z_max && a_z_max >= b_z_min;

	if(x_overlap && y_overlap && z_overlap)
	{
		return true;
	}

	return false;
}