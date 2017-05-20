#pragma once
#include "Shape.h"

class SawBlade :public Shape
{
public:
	SawBlade(GLfloat l,	GLuint nOfteeth,GLfloat toothW,GLfloat tootH,GLfloat toothS);
	~SawBlade();
private:
	void addTriangle1();
	void addTriangle2();
	void addTriangle3();
	void addTriangle4();
	void addTriangle5();

	glm::vec3 makePoint1();
	glm::vec3 makePoint2();
	glm::vec3 makePoint3();
	glm::vec3 makePoint4();
	glm::vec3 makePoint5();
	glm::vec3 makePoint6();

	GLfloat fullLength;
	GLuint	numberOfteeth;
	GLfloat toothWidth;
	GLfloat toothHeight;
	GLfloat toothSet;
	GLfloat toothLength;
	GLsizei verricesInTooth;
	GLsizei trianglesInTooth;
	GLfloat halfLength;
	GLfloat baseHeight;
	GLfloat halfToothWidth;
	GLfloat halfToothLength;
	GLfloat minusHalfToothWidth;
	GLsizei currentVecIndex;
	GLboolean inverted;

};

