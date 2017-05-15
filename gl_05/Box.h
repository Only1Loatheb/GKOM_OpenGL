#pragma once

#include "Shape.h"
class Box :public Shape
{
public:
	Box();
	~Box();
private:
	void calcNormalVec(vector<GLfloat>&);
};

