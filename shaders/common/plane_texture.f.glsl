R"===(
#version 460 core

// IN
layout (location = 0) in vec2 in_position;
layout (location = 1) in vec3 in_color;
layout (location = 2) in vec2 in_uv;

// OUT
layout (location = 0) out vec4 out_color;

uniform sampler2D u_texture;

void main() { 

  vec4 texture_color = texture(u_texture, in_uv);

  out_color = vec4(in_color + texture_color.rgb, 1.0);
}

)==="