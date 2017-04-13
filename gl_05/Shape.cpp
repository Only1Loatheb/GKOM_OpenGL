#include "Figure.h"	


Shape::Shape()
:w(8),
h(8),
i(5)
{

	vertices = new GLfloat[w * h]{
		// coordinates			// color			// texture
		 0.25f,  0.5f,  0.0f,	1.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		-0.75f,  0.5f,  0.0f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,
		-0.25f, -0.5f,  0.0f,	0.0f, 0.0f, 1.0f,	0.0f,  1.0f,
	 	 0.75f, -0.5f,  0.0f,	1.0f, 0.0f, 1.0f,	1.0f,  1.0f,
		 0.25f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		 -0.75f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,
		 -0.25f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,	0.0f,  1.0f,
		 0.75f, -0.5f,  0.5f,	1.0f, 0.0f, 1.0f,	1.0f,  1.0f,
	};
	indices = new GLuint[i * 3]{
		0, 1, 2,
		0, 2, 3,
		4, 5, 6,
		4, 6, 7,
		0, 1, 4,
	};
}


Shape::~Shape()
{}

GLfloat* Shape::getVertices() const
{
	return vertices;
}
GLuint* Shape::getIndices() const
{
	return indices;
}

GLsizeiptr Shape::sizeofVertices() const
{
	return sizeof(GLfloat) * w * h;
}

GLsizeiptr Shape::sizeofIndices() const
{
	return sizeof(GLuint) * i * 3;
}
