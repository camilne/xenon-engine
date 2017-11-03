#version 330

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec2 v_texCoords;

out vec3 f_position;
out vec2 f_texCoords;

uniform mat4 m_model;
uniform mat4 m_view;
uniform mat4 m_proj;

void main() {
    gl_Position = m_proj * m_view * m_model * vec4(v_position, 1.0);
    f_position = gl_Position.xyz;
    f_texCoords = v_texCoords;
}