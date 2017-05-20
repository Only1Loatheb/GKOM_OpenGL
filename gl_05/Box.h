#pragma once
#include "Shape.h"

class Box :public Shape
{
public:
	Box(GLfloat side);
	Box(GLfloat x, GLfloat y, GLfloat z );
	~Box();
private:
	void addVertices();
	void addIndices();
	void calcNormalVec(vector<GLfloat>&);
	GLfloat halfX;
	GLfloat halfY;
	GLfloat halfZ;
	GLsizei vertexAtribCount;
	GLsizei indicesInTriangle;
	GLsizei verticesCount;
	GLsizei indicesCount;
};

