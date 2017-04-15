#include "Figure.h"	
 

Shape::Shape()
:vertexAtributesCount(8),
verticesCount(24 * vertexAtributesCount),
indicesCount(12 * 3)
{

	vertices = vector<GLfloat>{
		// coordinates			// color			// texture
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,
		0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
	
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,
		0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
		
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
	};
	indices = vector<GLuint>();
	for (int i = 0; i < indicesCount; i+=4)
	{
		indices.push_back(i);
		indices.push_back(i+1);
		indices.push_back(i+2);
		indices.push_back(i+1);
		indices.push_back(i);
		indices.push_back(i+3);
	}
}


Shape::~Shape()
{}

GLfloat* Shape::getVertices() const
{
	return (GLfloat*)&vertices[0];
}
GLuint* Shape::getIndices() const
{
	return (GLuint*)&indices[0];
}

GLsizeiptr Shape::sizeofVertices() const
{
	return sizeof(GLfloat) * verticesCount;
}

GLsizeiptr Shape::sizeofIndices() const
{
	return sizeof(GLuint) * indicesCount;
}

GLsizei Shape::countofIndices() const
{
	return indicesCount;
}
