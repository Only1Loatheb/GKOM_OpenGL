#pragma once
#include "Animation.h"

#define FORWARD 1u
#define BACKWARD 2u
#define INIT 3u
#define WAITING 4u

class SawingAnimation : public Animation
{
public:
	SawingAnimation( GLfloat loopT, GLfloat sawingTime, GLuint swings);
	~SawingAnimation();
	void animate(glm::mat4& local, GLfloat dt) override;
private:
	GLuint state;
	GLuint swing;
	GLfloat goBackwardTime;
	GLfloat currentSwingTime;
	GLuint numberOfSwings;
	GLfloat	swingTime;
	glm::vec3 forwardSpeed;
	glm::vec3 backwardSpeed;
	glm::mat4 startingLocal;
};

