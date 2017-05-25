#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/glm.hpp>

class Animation
{
public:
	Animation(GLfloat loopT);
	~Animation();
	virtual void animate(glm::mat4& local, GLfloat dt) = 0;
protected:
	GLfloat currentTime;
	GLfloat loopTime;
};

