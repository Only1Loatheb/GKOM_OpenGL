#pragma once
#include "Animation.h"

#define INIT 1u
#define WAITING 2u
#define FALLING 3u

class SplitingAnimation : public Animation
{
public:
	SplitingAnimation( GLfloat loopT,GLfloat start, GLboolean side);
	~SplitingAnimation();
	void animate(glm::mat4& local, GLfloat dt) override;
private:
	GLuint state;
	glm::mat4 startingLocal;
	GLfloat startFallingTime;
	GLfloat theta;
	GLfloat fallingTime;
	glm::vec3 rotateAround;
	glm::vec3 translation;
};

