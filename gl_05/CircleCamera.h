#pragma once
#include "Camera.h"
class CircleCamera: public Camera
{
public:
	CircleCamera(GLfloat, GLfloat);
	~CircleCamera();
	virtual void update(GLfloat);
private:
	glm::mat4 rotation;
	GLfloat radius;
	GLfloat height;
};

