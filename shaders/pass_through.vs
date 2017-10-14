#version 330

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec2 v_texcoords;

out vec3 f_position;
out vec2 f_texcoords;

void main() {
    gl_Position = vec4(v_position, 1.0);
    f_position = v_position;
    f_texcoords = v_texcoords;
}