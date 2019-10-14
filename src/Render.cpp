#include "Render.h"

// extern globals from Render.h
GLuint models_vao;
GLuint models_vbo;


void init_default_shader()
{

}


void set_default_shader_uniforms(glm::mat4 view, glm::mat4 proj, std::vector<Light> &lights) // maybe need to pass in model, but that's probably model.transform?
{

}


void draw_geometry(std::vector<Model> &models)
{

}


void delete_buffers()
{
	glDeleteBuffers(1, &models_vbo);
	glDeleteVertexArrays(1, &models_vao);
}