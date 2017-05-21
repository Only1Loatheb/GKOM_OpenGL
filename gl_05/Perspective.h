#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp>

class Perspective
{
public:
	Perspective(GLuint, GLuint);
	~Perspective();
	glm::mat4 getTransformationMatrix(const glm::mat4&)const;
private:
	glm::mat4 proj;
};
