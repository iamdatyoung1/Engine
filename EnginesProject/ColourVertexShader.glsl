#version 450 core
//This has to be in order
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 texCoords;
layout(location = 3) in vec3 colour;

out vec3 Normal;
out vec2 TexCoords;
out vec3 Colour;

void main(){
//The code below with position can only be in vertex
    gl_Position = vec4(posiition, 1.0f);
    Colour = colour;
}