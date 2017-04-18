#include "CircleCamera.h"

CircleCamera::CircleCamera(GLfloat r, GLfloat h)
	:Camera(),
	startingPos(cameraPos),
	rotation(glm::mat4()),
	radius(r),
	height(h)
{}

CircleCamera::~CircleCamera()
{
}

void CircleCamera::update(GLfloat dt, std::shared_ptr<ShaderProgram>& program)
{	
	GLfloat speed = 0;
	if (Controller::iKBP(GLFW_KEY_A))
		speed -= 100.0f;
	if (Controller::iKBP(GLFW_KEY_D))
		speed += 100.0f;
	rotation = glm::rotate(rotation, glm::radians(dt * speed), up);
	cameraPos = glm::vec3(rotation * glm::vec4(startingPos, 1.0f));
	view = glm::lookAt(cameraPos, cameraTarget, up);
	Camera::addCametaPosToSh(program);
}
