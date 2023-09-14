#version 330 core

out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D sprite;
uniform float time;

void main()
{
    vec4 color = texture(sprite, texCoord);
    FragColor = color;
}