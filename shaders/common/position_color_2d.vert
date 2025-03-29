#version 460 core

// IN
layout (location = 0) in vec2 in_position;
layout (location = 1) in vec3 in_color;

// OUT
layout (location = 0) out vec2 out_position;
layout (location = 1) out vec3 out_color;

out gl_PerVertex {
  vec4 gl_Position;
};

void main() {
  gl_Position = vec4(in_position, 0.0, 1.0);
  out_position = in_position;
  out_color = in_color;
}