#version 330

in vec3 f_position;
in vec2 f_texcoords;

out vec3 out_color;

uniform sampler2D buffer;

void main() {
    out_color = texture(buffer, f_texcoords).xyz;
}