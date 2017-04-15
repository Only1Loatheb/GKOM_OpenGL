#pragma once
#include <GL/glew.h>
#include <vector>
using namespace std;

class Shape
{
public:
	Shape();
	~Shape();
	virtual GLfloat* getVertices() const;
	virtual GLuint* getIndices() const;
	GLsizeiptr sizeofVertices() const;
	GLsizeiptr sizeofIndices() const;
	GLsizei countofIndices() const;
protected:
	GLsizei vertexAtributesCount;
	GLsizei verticesCount;
	GLsizei indicesCount;
	vector<GLfloat> vertices;
	vector<GLuint> indices;

	//virtual void init();
};

