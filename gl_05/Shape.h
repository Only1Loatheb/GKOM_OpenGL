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
	//OpenGL
	GLfloat* getVerticesAdress() const;
	GLuint* getIndicesAdress() const;
	GLsizeiptr sizeOfVertices() const;
	GLsizeiptr sizeOfIndices() const;
	void bindVAO();
	//utils
	glm::vec3 calcNormalVec(const glm::vec3&, const glm::vec3&, const glm::vec3 &);
	void saveVertexToVector(const glm::vec3&, const glm::vec3&, const glm::vec2&);
	void saveIndicesToVector(const GLuint&, const GLuint&, const GLuint&);
	//used in cylinder
	GLsizei countOfTriangles() const;
	GLsizei countOfVertices() const;
	//used in box, not good practise
	GLsizei getVertexAtributesCount() const;
	void setVertices(const vector<GLfloat>&&); 
	vector<GLfloat>& getVertices(); 
	vector<GLuint>& getIndices(); 
private:
	GLsizei vertexAtributesCount;
	GLsizei indicesInTriangle;
	GLuint VBO;
	GLuint EBO;
	GLuint VAO;
	vector<GLfloat> vertices;
	vector<GLuint> indices;

};