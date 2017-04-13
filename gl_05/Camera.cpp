#include "Camera.h"



Camera::Camera()
:cameraPos(glm::vec3(0.0f, 0.0f, 3.0f)),
cameraTarget(glm::vec3(0.0f, 0.0f, 0.0f)),
cameraDirection(glm::normalize(cameraPos - cameraTarget)),
up(glm::vec3(0.0f, 1.0f, 0.0f)),
cameraRight(glm::normalize(glm::cross(up, cameraDirection))),
cameraUp(glm::cross(cameraDirection, cameraRight)),
view(glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f)))
{
}


Camera::~Camera()
{
}

glm::mat4 Camera::getView() const
{
	return view;
}