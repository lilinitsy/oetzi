#version 330 core

in vec2 texcoords;
in vec2 normal_colour_mapping;

out vec4 fragment_colour;

uniform sampler2D texture_diffuse1;

void main()
{
    fragment_colour = texture(texture_diffuse, texcoords);
    fragment_colour.rgb = pow(fragment_colour.rgb, vec3(1.0 / 2.2)); // gamma correction
}
