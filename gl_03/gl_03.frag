#version 330 core

in vec3 ourColor;
out vec4 color;
  
void main()//doing nothing but adding alpha
{
    color = vec4(ourColor, 1.0f);
}
