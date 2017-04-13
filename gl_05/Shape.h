#pragma once
#include <GL/glew.h>
class Shape
{
public:
	Shape();
	~Shape();
	virtual GLfloat* getVertices() const;
	virtual GLuint* getIndices() const;
	GLsizeiptr sizeofVertices() const;
	GLsizeiptr sizeofIndices() const;

private:
	GLfloat* vertices;
	GLuint* indices;
	GLuint w ;
	GLuint h ;
	GLuint i ;
};

