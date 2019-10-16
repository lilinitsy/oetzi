#version 330 core
layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_texcoords;

out vec2 texcoords;
out vec3 normal_colour_mapping;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    normal_colour_mapping = in_normal;
    texcoords = in_texcoords;
    gl_Position = projection * view * model * vec4(in_position, 1.0);
}
