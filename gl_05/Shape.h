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
	GLsizei countofIndices() const;
protected:
	GLfloat* vertices;
	GLuint* indices;
	GLsizei w ;
	GLsizei h ;
	GLsizei i ;
};

