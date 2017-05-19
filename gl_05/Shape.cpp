#include "Figure.h"	
 

Shape::Shape()
{
	vertexAtributesCount = 8;
	indicesInTriangle = 3;
	vertices = vector<GLfloat>();
	indices = vector<GLuint>();
}


Shape::~Shape()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

GLfloat* Shape::getVerticesAdress() const
{
	return (GLfloat*)&vertices[0];
}
GLuint* Shape::getIndicesAdress() const
{
	return (GLuint*)&indices[0];
}

GLsizeiptr Shape::sizeOfVertices() const
{
	return sizeof(GLfloat) * vertices.size();
}

GLsizeiptr Shape::sizeOfIndices() const
{
	return sizeof(GLuint) * indices.size();
}

GLsizei Shape::countOfTriangles() const
{
	return indices.size() / indicesInTriangle;
}

GLsizei Shape::countOfVertices() const
{
	return vertices.size() / vertexAtributesCount;
}

void Shape::bindVAO()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeOfVertices(), getVerticesAdress(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfIndices(), getIndicesAdress(), GL_STATIC_DRAW);

	// vertex geometry data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// vertex color data
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// vertex texture coordinates
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

}


void Shape::draw() const
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

GLsizei Shape::getVertexAtributesCount() const
{
	return vertexAtributesCount;
}


glm::vec3 Shape::calcNormalVec(const glm::vec3 & p1, const glm::vec3 & p2, const glm::vec3 & p3)
{
	return glm::cross(p2 - p1, p3 - p1);
}

void Shape::saveVertexToVector(const glm::vec3 & pos, const glm::vec3 & norm, const glm::vec2 & tex)
{
	vertices.push_back(pos.x);
	vertices.push_back(pos.y);
	vertices.push_back(pos.z);
	vertices.push_back(norm.x);
	vertices.push_back(norm.y);
	vertices.push_back(norm.z);
	vertices.push_back(tex.x);
	vertices.push_back(tex.y);
	//memcpy(&v[index], &normal.x, sizeOf3Floats);
}

void Shape::saveIndicesToVector(const GLuint & i1, const GLuint & i2, const GLuint & i3)
{
	indices.push_back(i1);
	indices.push_back(i2);
	indices.push_back(i3);
}

void Shape::setVertices(const vector<GLfloat>&& v)
{
	vertices = std::move(v);
}

vector<GLfloat>& Shape::getVertices()
{
	return vertices;
}

vector<GLuint>& Shape::getIndices()
{
	return indices;
}
