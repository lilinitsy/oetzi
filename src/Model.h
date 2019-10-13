#ifndef MODEL_H
#define MODEL_H

#include "ModelInstance.h"

struct Model
{
	int id = -1;
	std::string name;
	ModelInstance *model_instance = nullptr;
	std::vector<Model*> child_models;
	glm::mat4 transform;
};

extern Model global_model_list[10000];
extern unsigned int num_models;

 // OPERATE AS DATA - > ADDING MODELS MAYBE DONE THROUGH GAMEMANAGER?
void load_model(std::string filename);
void add_child(std::string child_name, int current_model_id);
int add_model(std::string model_name);

#endif