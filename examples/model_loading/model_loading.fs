#version 330

in vec3 f_position;
in vec2 f_texCoords;

layout(location = 0) out vec3 out_color;

uniform sampler2D texture_diffuse1;

void main() {
    out_color = texture(texture_diffuse1, vec2(f_texCoords.s, f_texCoords.t)).rgb;
}