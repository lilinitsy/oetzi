#ifndef RENDER_H
#define RENDER_H

#include "Model.h"
#include "Lights.h"

extern GLuint models_vbo;
extern GLuint models_vao;

void init_default_shader();
void set_default_shader_uniforms(glm::mat4 view, glm::mat4 proj, std::vector<Light> lights); // maybe need to pass in model, but that's probably model.transform?
void draw_geometry(std::vector<Model> models);
void delete_buffers();

#endif