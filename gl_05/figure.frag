#version 330 core
in vec3 vecNormal;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D Texture0;
uniform vec3 lightPos;

void main()
{
    color = texture(Texture0, TexCoord);
}
