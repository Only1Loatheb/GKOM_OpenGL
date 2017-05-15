#version 330 core

in vec2 TexCoord;
out vec4 color;

uniform sampler2D Texture0;
uniform vec3 lightColor;

#define ambientStrength 1.0f

void main()
{
    //vec3 ambient = ambientStrength * lightColor;
	color = texture(Texture0, TexCoord);// * vec4(ambient, 1.0f);
}
