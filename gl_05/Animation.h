#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

