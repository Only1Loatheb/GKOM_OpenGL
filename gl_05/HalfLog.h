#pragma once
#include "Shape.h"

class HalfLog : public Shape
{
public:
	HalfLog();
	~HalfLog();
private:
	GLfloat radius;
	GLfloat height;
	GLuint slices; // slices = no. of Longitude lines
	GLfloat minusHeight;
	double theta;
	double halfTheta;
	glm::vec3 zeroZeroOne;
	glm::vec3 zeroZeroMinusOne ;
};
float randFloat();
glm::vec2 randomVec2();

