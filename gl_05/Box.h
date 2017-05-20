#pragma once
#include "Shape.h"

class Box :public Shape
{
public:
	Box(GLfloat side);
	~Box();
private:
	void addVertices();
	void addIndices();
	void calcNormalVec(vector<GLfloat>&);
	GLfloat halfSide;
	GLsizei vertexAtribCount;
	GLsizei indicesInTriangle;
	GLsizei verticesCount;
	GLsizei indicesCount;
};

