#pragma once
#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere();
	~Sphere();
private:
	GLfloat radius;
	GLuint stacks; // stacks = no. of Latitude lines,
	GLuint slices; // slices = no. of Longitude lines
	double deltaLong;
	double deltaLat;
};

