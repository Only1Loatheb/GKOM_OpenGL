#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>

#include <stdexcept>
#include <string>
class Texture
{
public:
	Texture(GLuint , const char*);
	~Texture();
	void bind()const;
private:
	GLuint texture;
	GLuint texId;
	int width, height;
};

