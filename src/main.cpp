#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>



#include <external/imgui/imgui.h>
#include <external/imgui/imgui_impl_sdl.h>
#include <external/imgui/imgui_impl_opengl3.h>


#include "AABB.h"
#include "GameManager.h"
#include "Lights.h"
#include "luasupport.h"
#include "Model.h"
#include "Render.h"
#include "GPU-Includes.h"
#include "Shader.h"
#include "utils.h"
#include "WindowManager.h"

#include "glad/glad.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

#define STB_IMAGE_IMPLEMENTATION	   //put this line in only one .cpp file
#define STB_IMAGE_WRITE_IMPLEMENTATION //only place once in one .cpp files

#include <external/stb_image.h>

#include <external/loguru.hpp>

int main()
{

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC);  //Initialize Graphics (for OpenGL) and Audio (for sound) and Game Controller


	createOpenGLWindow(1280, 720, false);
	initIMGui();

	printf("RUNNING\n");

	AABB *a = new AABB;
	a->position = glm::vec3(0.0f, 0.0f, 0.0f);
	a->extents = glm::vec3(1.0f, 1.0f, 1.0f);


	Shader default_shader("shaders/vertex_basic.glsl", "shaders/fragment_basic.glsl");
	default_shader.use();
	


	// Create a test gameobject.	
	load_model("models/simpleCube.obj");

	GameManager game_manager = {};
	// add a gameobject
	game_manager.names.push_back("test_model");
	game_manager.positions.push_back(a->position);
	game_manager.models.push_back(global_model_list[0]);
	game_manager.aabbs.push_back(*a);

	

	SDL_Event windowEvent;
	bool quit = false;
	while(!quit)
	{
		while(SDL_PollEvent(&windowEvent))
		{
			if (windowEvent.type == SDL_KEYUP && windowEvent.key.keysym.sym == SDLK_ESCAPE) quit = true; //Exit event loop		}
		}
		glClearColor(0,0,0,1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		for(unsigned int i = 0; i < game_manager.models.size(); i++)
		{
			
		}

		for(unsigned int i = 0; i < num_models; i++)
		{
			global_model_list[i].model_instance->draw(default_shader);
		}




		IMGuiNewFrame();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		//LOG_F(3,"Done Drawing");
		swapDisplayBuffers();
	}



	//GameManager game_manager = {};

	
	return 0;
}