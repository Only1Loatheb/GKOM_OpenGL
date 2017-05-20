#include "Perspective.h"

Perspective::Perspective(GLuint width, GLuint height)
{
	proj = glm::perspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
	//model = glm::rotate(model, -55.0f, glm::vec3(1.0f, 0.0f, 0.0f));
}

Perspective::~Perspective()
{
}

glm::mat4 Perspective::getTransformationMatrix(const glm::mat4& view) const
{
	return proj * view;
}

