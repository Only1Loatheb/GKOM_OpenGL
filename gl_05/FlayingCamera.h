#pragma once
#include "Camera.h"

class FlayingCamera: public Camera
{
public:
	FlayingCamera();
	~FlayingCamera();
	void update(GLfloat, std::shared_ptr<ShaderProgram>&) override;
private:
	glm::vec3 cameraFront;
	GLfloat cameraSpeed;
};

