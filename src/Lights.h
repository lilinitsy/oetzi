#ifndef LIGHTS_H
#define LIGHTS_H


#include "glm/glm.hpp"

#include <vector>
#include <string>


enum LightType
{
	POINT,
	DIRECTIONAL,
	SPOT
};


// Direction should be normalized.
struct Light
{
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 direction = glm::vec3(0.0f, 0.0f, 1.0f);
	float distance = 10;
	float intensity = 3;
	int pcfWidth = 1;
	LightType type = POINT;
	std::string name = "";
};

#endif