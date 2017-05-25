#pragma once
#include "Animation.h"

class SplitingAnimation : public Animation
{
public:
	SplitingAnimation( GLfloat loopT,GLfloat start,
		GLfloat end, GLboolean side);
	~SplitingAnimation();
	void animate(glm::mat4& local, GLfloat dt) override;
private:
	GLuint state;
	glm::mat4 startingLocal;
	GLfloat startFallingTime;
	GLfloat theta;
	GLfloat fallingTime;
	GLfloat endFalingTime;
	glm::vec3 rotateAround;
	glm::vec3 translation;
};