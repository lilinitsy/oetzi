#ifndef RENDER_H
#define RENDER_H

#include "Model.h"
#include "Lights.h"
#include "Shader.h"

extern GLuint models_vbo;
extern GLuint models_vao;


// maybe store normals as a new type, row vector, and vertices as a column vector


void init_default_shader(Shader shader);
void set_default_shader_uniforms(glm::mat4 view, glm::mat4 proj, std::vector<Light> lights); // maybe need to pass in model, but that's probably model.transform?
void draw_geometry(std::vector<Model> models);
void render_scene(std::vector<Model> models, glm::vec3 forward, glm::vec3 camera_position, float near, float far);
void delete_buffers();

#endif