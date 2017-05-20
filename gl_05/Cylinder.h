#pragma once
#include "Shape.h"

class Cylinder : public Shape
{
public:
	Cylinder(GLfloat r,GLfloat h,GLuint sides);
	~Cylinder();
private:
	void addSideVertices();
	void addLidsVertices();
	void addSideIndices();
	void addLidsIndices();

	GLfloat radius;
	GLfloat heightHalf;
	GLuint sides; // slices = no. of Longitude lines
	GLfloat minusHeightHalf;
	double theta;
	double halfTheta;
	glm::vec3 zeroZeroOne;
	glm::vec3 zeroZeroMinusOne;
	float randFloat()const;
	glm::vec2 randomVec2()const;
};


