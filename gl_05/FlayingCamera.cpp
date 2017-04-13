#include "FlayingCamera.h"



FlayingCamera::FlayingCamera()
	:Camera(),
	cameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
{
}

FlayingCamera::~FlayingCamera()
{
}

void FlayingCamera::update(GLuint dt)
{
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
