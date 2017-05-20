#pragma once
#include <vector>
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Figure.h"

class Perspective
{
public:
	Perspective(GLuint, GLuint);
	~Perspective();
	glm::mat4 getTransformationMatrix(const glm::mat4&)const;
private:
	glm::mat4 proj;
};
