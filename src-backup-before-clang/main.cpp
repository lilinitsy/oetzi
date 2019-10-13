//#include "glad/gladh.h"
/*
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_mixer.h>
*/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "AABB.h"
#include "GPU-Includes.h"
#include "Shader.h"
#include "utils.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

#define STB_IMAGE_IMPLEMENTATION //put this line in only one .cpp file
#define STB_IMAGE_WRITE_IMPLEMENTATION //only place once in one .cpp files

#include <external/stb_image.h>

#include <external/loguru.hpp>

int main()
{
	printf("RUNNING\n");

	AABB *a = new AABB;
	a->position = glm::vec3(0.0f, 0.0f, 0.0f);
	a->extents = glm::vec3(1.0f, 1.0f, 1.0f);

	AABB *b = new AABB;
	b->position = glm::vec3(0.5f, 0.5f, 0.5f);
	b->extents = glm::vec3(0.5f, 0.5f, 0.5f);

	printf("a and b overlap? %d\n", AABB_overlap(a, b));
	return 0;
}