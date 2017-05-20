#include "SawingAnimation.h"

SawingAnimation::SawingAnimation( GLfloat loopT, GLfloat sawingTime, GLuint swings)
	:Animation(loopT), currentSwingTime(0.f)
{
	state = INIT;
	GLfloat dy = -1.3f / sawingTime;
	forwardSpeed = glm::vec3(1.f,dy,0.f);
	backwardSpeed = glm::vec3(-1.f, dy, 0.f);
	swingTime = sawingTime / swings;
	goBackwardTime = swingTime / 2.0f;
	numberOfSwings = swings;
	swing = 0;
}

SawingAnimation::~SawingAnimation()
{
}

void SawingAnimation::animate(glm::mat4 & local, GLfloat dt)
{
	currentTime += dt;
	if (state == FORWARD)
	{
		currentSwingTime += dt;
		local = glm::translate(local, dt * forwardSpeed);
		if (currentSwingTime > goBackwardTime)
		{
			state = BACKWARD;
		}
		return;
	}
	else if (state == BACKWARD)
	{
		currentSwingTime += dt;
		local = glm::translate(local, dt * backwardSpeed);
		if (currentSwingTime > swingTime)
		{
			state = FORWARD;
			++swing;
			currentSwingTime = 0.f;
			if (swing == numberOfSwings)
			{
				state = WAITING;
			}
			
		}
		return;
	}
	else if (state == WAITING)
	{
		if (currentTime > loopTime)
		{
			currentTime = 0.f;
			local = startingLocal;
			swing = 0u;
			state = FORWARD;
		}
		return;
	}
	else if(state == INIT)
	{
		startingLocal = local;;
		state = FORWARD;
		return;
	}
}
