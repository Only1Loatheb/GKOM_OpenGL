#include "CircleCamera.h"

CircleCamera::CircleCamera(GLfloat r, GLfloat h)
	:Camera(),
	rotation(glm::mat4())
{
	radius = r;
	height = h;
}

CircleCamera::~CircleCamera()
{
}

void CircleCamera::update(GLfloat dt)
{	
	GLfloat speed = 10.0f;
	rotation = glm::rotate(rotation, glm::radians(dt * speed), up);
	view = glm::lookAt(glm::vec3(rotation * glm::vec4(cameraPos, 1.0f)) , cameraTarget, up);
}
