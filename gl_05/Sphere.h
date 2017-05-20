#pragma once
#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere(GLfloat r, GLuint stacks, GLuint slices);
	~Sphere();
private:
	void addNorthVertice();
	void addMainVertices();
	void addSouthVerttice();
	void addNorthIndices();
	void addMainIndices();
	void addSouthIndices();
	GLfloat radius;
	GLuint stacks; // stacks = no. of Latitude lines,
	GLuint slices; // slices = no. of Longitude lines
	double deltaLong;
	double deltaLat;
};

