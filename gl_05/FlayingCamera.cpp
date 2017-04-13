#include "FlayingCamera.h"

FlayingCamera::FlayingCamera()
	:Camera(),
	cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
	cameraSpeed(0.05f)
{
}

FlayingCamera::~FlayingCamera()
{
}

void FlayingCamera::update(GLfloat dt)
{
	cameraSpeed = 5.0f * dt;

	if(Controller::iKBP(GLFW_KEY_W))
		cameraPos += cameraSpeed * cameraFront;
	if (Controller::iKBP(GLFW_KEY_S))
		cameraPos -= cameraSpeed * cameraFront;
	if (Controller::iKBP(GLFW_KEY_A))
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (Controller::iKBP(GLFW_KEY_D))
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
