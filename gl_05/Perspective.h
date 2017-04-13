#pragma once
#include <vector>
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
	void update(const glm::mat4,std::vector<Figure>&);
private:
	glm::mat4 proj;
	glm::mat4 model;
	glm::mat4 projection;
};
