#pragma once
#define GLEW_STATIC
#include <GL/glew.h>

#include <fstream>
#include <sstream>
#include <iostream>
class VertexShader
{
public:
	VertexShader(const GLchar* vertexPath);
	~VertexShader();
	GLuint getVertex();
private:
	GLuint vertex;
};

