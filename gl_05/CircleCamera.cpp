#include "CircleCamera.h"

CircleCamera::CircleCamera(GLfloat r, GLfloat h)
	:Camera()
{
	radius = r;
	height = h;
}

CircleCamera::~CircleCamera()
{
}

void CircleCamera::update(GLfloat dt)
{	
	GLfloat speed = 1.0f;
	cameraPos = glm::rotate(cameraPos, glm::radians(dt * speed), up);
	view = glm::lookAt(cameraPos, cameraTarget, up);
}
