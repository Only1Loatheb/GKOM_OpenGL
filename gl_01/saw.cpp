#include "saw.h"


Saw::Saw()
{
	numVertices = 9;

	vertices = new GLfloat[numVertices]{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	numIndices = 6;

	indices = new GLuint[numIndices]{
		0, 1, 3,
		1, 2, 3
	};

}


Saw::~Saw()
{
}
