#pragma once
#include "Camera.h"

class FlayingCamera: public Camera
{
public:
	FlayingCamera();
	~FlayingCamera();
	virtual void update(GLfloat);
private:
	glm::vec3 cameraFront;
	GLfloat cameraSpeed;
};

