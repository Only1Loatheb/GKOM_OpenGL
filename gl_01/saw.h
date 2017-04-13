#pragma once
#include <GL/glew.h>
class Saw
{
public:
	Saw();
	~Saw();

	GLuint numVertices;
	GLfloat* vertices;
	GLuint numIndices;
	GLuint* indices;
};

