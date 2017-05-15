#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp> // GLM handles matrix mathematics
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
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
	GLfloat* getVertices() const;
	GLuint* getIndices() const;
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