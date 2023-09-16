#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 texCoord;

uniform mat4 model;
uniform mat4 projection_view;
uniform float time;

void main()
{
    vec3 pos = aPos;
    pos *= 1.0f + cos(time * 2.0f) * 0.3f;

    gl_Position = projection_view * model * vec4(pos, 1.0f);
    texCoord = aTexCoord;
}