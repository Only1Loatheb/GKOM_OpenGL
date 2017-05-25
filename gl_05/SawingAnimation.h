#pragma once
#include "Animation.h"

class SawingAnimation : public Animation
{
public:
	SawingAnimation( GLfloat loopT, GLfloat startSawingTime, 
		GLfloat sawingTime, GLuint swings);
	~SawingAnimation();
	void animate(glm::mat4& local, GLfloat dt) override;
private:
	GLfloat currentSwingTime;
	GLfloat startSawingTime;
	GLuint state;
	GLuint swing;
	GLfloat sawingTime;
	GLfloat	swingTime;
	GLfloat goBackwardTime;
	glm::vec3 forwardSpeed;
	glm::vec3 backwardSpeed;
	GLuint numberOfSwings;




	glm::mat4 startingLocal;
};

