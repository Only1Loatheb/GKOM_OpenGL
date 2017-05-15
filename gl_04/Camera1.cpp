#include "Camera1.h"

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(this->Position, this->Position + this->Front, this->Up);	
}

void Camera::ProcessMouseScroll()
{
	GLfloat yoffset = Controller1::getScrollOffset();
	if (this->Zoom >= 1.0f && this->Zoom <= 45.0f)
		this->Zoom -= yoffset;
	if (this->Zoom <= 1.0f)
		this->Zoom = 1.0f;
	if (this->Zoom >= 45.0f)
		this->Zoom = 45.0f;
}

void Camera::do_movement(GLfloat deltaTime)
{
	GLfloat velocity = this->MovementSpeed * deltaTime;
	// Camera controls
	if (Controller1::isKeyPressed(GLFW_KEY_W))
		this->Position += this->Front * velocity;
	if (Controller1::isKeyPressed(GLFW_KEY_S))
		this->Position -= this->Front * velocity;
	if (Controller1::isKeyPressed(GLFW_KEY_A))
		this->Position -= this->Right * velocity;
	if (Controller1::isKeyPressed(GLFW_KEY_D))
		this->Position += this->Right * velocity;
}
