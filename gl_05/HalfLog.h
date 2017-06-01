#pragma once
#include "Shape.h"

class HalfLog : public Shape
{
public:
	HalfLog(GLfloat r, GLfloat h, GLuint slices, GLfloat part);
	~HalfLog();
private:
	void addSideVertices();
	void addLidsVertices();
	void addSideIndices();
	void addLidsIndices();
	void addCutVertInd();
	GLfloat radius;
	GLfloat heightHalf;
	GLfloat part;
	GLuint sides;
	double theta;
	GLfloat minusHeightHalf;
	glm::vec3 zeroZeroOne;
	glm::vec3 zeroZeroMinusOne;
	float randFloat()const;
	glm::vec2 randomVec2()const;
};


