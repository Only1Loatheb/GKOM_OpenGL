#pragma once
#include "Camera.h"
class CircleCamera: public Camera
{
public:
	CircleCamera(GLfloat, GLfloat);
	~CircleCamera();
	virtual void update(GLfloat);
	GLfloat radius;
	GLfloat height;
};

