#include "SawingAnimation.h"

SawingAnimation::SawingAnimation( GLfloat loopT, GLfloat startSawingTime, 
	GLfloat endSawingTime, GLuint swings)
	:Animation(loopT), currentSwingTime(0.f), startSawingTime(startSawingTime)
{
	state = INIT;
	sawingTime = endSawingTime - startSawingTime;
	swingTime = sawingTime / (GLfloat)swings;
	goBackwardTime = swingTime / 2.0f;
	GLfloat dy = -1.3f / sawingTime ;
	GLfloat dx = .5f / swingTime;
	forwardSpeed = glm::vec3(dx,dy,0.f);
	backwardSpeed = glm::vec3(-dx, dy, 0.f);
	numberOfSwings = swings;
	swing = 0;
}

SawingAnimation::~SawingAnimation()
{
}

void SawingAnimation::animate(glm::mat4 & local, GLfloat dt)
{
	currentTime += dt;
	if (state == PREPARING)
	{
		if (currentTime > startSawingTime)
		{
			state = FORWARD;
		}
		return;
	}
	else if (state == FORWARD)
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
			state = PREPARING;
		}
		return;
	}
	else if(state == INIT)
	{
		startingLocal = local;;
		state = PREPARING;
		return;
	}
}
