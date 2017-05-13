#include "Camera.h"



Camera::Camera()
:cameraPos(glm::vec3(0.0f, 0.0f, 3.0f)),
cameraTarget(glm::vec3(0.0f, 0.0f, 0.0f)),
up(glm::vec3(0.0f, 1.0f, 0.0f)),
cameraRight(glm::normalize(glm::cross(up, glm::normalize(cameraPos - cameraTarget)))),
cameraUp(glm::cross(glm::normalize(cameraPos - cameraTarget), cameraRight)),
view(glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f)))
{
}


Camera::~Camera()
{
}

const glm::mat4& Camera::getView() const
{
	return view;
}

void Camera::addCameraPosToSh(std::shared_ptr<ShaderProgram>& program) const
{
	GLint viewPosLoc = glGetUniformLocation(program->getProgramID(), "viewPos");
	glUniform3f(viewPosLoc, cameraPos.x, cameraPos.y, cameraPos.z);
}

