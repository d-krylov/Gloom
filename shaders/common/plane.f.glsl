R"===(
#version 460 core

// IN
layout (location = 0) in vec2 in_position;
layout (location = 1) in vec3 in_color;

// OUT
layout (location = 0) out vec4 out_color;

void main() {  
  out_color = vec4(in_color, 1.0);
}

)==="