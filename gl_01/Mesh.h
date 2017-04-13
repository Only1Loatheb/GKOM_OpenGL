#pragma once
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
class Mesh
{
public:
	Mesh(GLfloat *vertices, unsigned int numVertices, GLuint *indices, unsigned int numIndices);
	~Mesh();
	void draw();
private:
	GLuint VBO, VAO, EBO;
	int num_ind;
};
