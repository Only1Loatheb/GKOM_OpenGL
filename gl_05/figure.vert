#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec3 fragPos;
out vec3 vecNormal;
out vec2 TexCoord;
  
uniform mat4 transform; //mamy zmienna z macierza translacji
uniform mat4 local;
uniform mat3 inverted;
void main()
{
    fragPos = (local * vec4(position, 1.0f)).xyz;
	vecNormal = inverted * normal;
    TexCoord = texCoord;
	gl_Position = transform * vec4(position, 1.0f);  //tu jedno mnozenie
} 