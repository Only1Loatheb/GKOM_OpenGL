#pragma once
#include <GL/glew.h>
#include <vector>
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

	GLsizei vertexAtributesCount;
	GLsizei verticesCount;
	GLsizei indicesCount;
	vector<GLfloat> vertices;
	vector<GLuint> indices;
	GLuint VBO, EBO, VAO;
	//virtual void init();
};

