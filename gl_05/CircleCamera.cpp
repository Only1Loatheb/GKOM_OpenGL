#include "CircleCamera.h"

CircleCamera::CircleCamera(GLfloat r, GLfloat h, GLfloat minr, GLfloat maxr,
	GLfloat minh,	GLfloat maxh)
	:Camera(), radius(r),height(h), minR(minr), maxR(maxr),	minH(minh),
	maxH(maxh)
{
	cameraPos = glm::vec3(r, h, 0.0f);
	zero = glm::vec3(0.0f);
	rotation = 0;
}

CircleCamera::~CircleCamera()
{
}

void CircleCamera::update(GLfloat dt, std::shared_ptr<ShaderProgram>& program)
{	
	GLfloat rotationSpeed = 0;
	GLfloat liftingSpeed = 0;
	GLfloat aproachingSpeed = 0;

	if (Controller::iKBP(GLFW_KEY_A))
		rotationSpeed -= 100.0f;
	if (Controller::iKBP(GLFW_KEY_D))
		rotationSpeed += 100.0f;
	if (Controller::iKBP(GLFW_KEY_Q))
		liftingSpeed -= 10.0f;
	if (Controller::iKBP(GLFW_KEY_E))
		liftingSpeed += 10.0f;
	if (Controller::iKBP(GLFW_KEY_W))
		aproachingSpeed -= 10.0f;
	if (Controller::iKBP(GLFW_KEY_S))
		aproachingSpeed += 10.0f;

	rotation += dt * rotationSpeed;
	if (rotation > 360)
		rotation -= 360;
	else if (rotation < 0)
		rotation += 360;

	radius += dt * aproachingSpeed;
	if (radius < minR)
		radius = minR;
	else if (radius > maxR)
		radius = maxR;

	height += dt * liftingSpeed;
	if (height < minH)
		height = minH;
	else if (height > maxH)
		height = maxH;

	auto local = glm::mat4();
	local = glm::rotate(local, glm::radians(rotation), up);
	local = glm::translate(local, glm::vec3(radius,height, 0.0f ));
	cameraPos = glm::vec3(local * glm::vec4(zero, 1.0f));
	view = glm::lookAt(cameraPos, cameraTarget, up);
	Camera::addCameraPosToSh(program);
}