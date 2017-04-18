#pragma once
#include <GL/glew.h>
#include <vector>
#include <iostream>
using namespace std;

class Shape
{
public:
	Shape();
	~Shape();
	void draw() const;
protected:
	virtual GLfloat* getVertices() const;
	virtual GLuint* getIndices() const;
	GLsizeiptr sizeofVertices() const;
	GLsizeiptr sizeofIndices() const;
	GLsizei countofIndices() const;

	void Shape::calcNormalVec(vector<GLfloat>&);

	GLsizei vertexAtributesCount;
	GLsizei verticesCount;
	GLsizei indicesCount;
	vector<GLfloat> vertices;
	vector<GLuint> indices;
	GLuint VBO, EBO, VAO;
	//virtual void init();
};