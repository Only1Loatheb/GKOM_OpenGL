#pragma once
#include "Camera.h"
class FlayingCamera: public Camera
{
public:
	FlayingCamera();
	~FlayingCamera();
	virtual void update(GLuint dt);
private:
	glm::vec3 cameraFront;
};

