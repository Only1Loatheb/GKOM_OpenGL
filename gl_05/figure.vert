#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec3 fragPos;
out vec3 vecNormal;
out vec2 TexCoord;
  
uniform mat4 model;
uniform mat4 transform;
uniform mat3 inversed;

void main()
{
    gl_Position = transform * vec4(position, 1.0f);
    fragPos = vec3(model * vec4(position, 1.0f));
    vecNormal = inversed * normal;  
    TexCoord = texCoord;
} 
