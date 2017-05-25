#include "SawingAnimation.h"
#include <glm/gtc/matrix_transform.hpp>

#define FORWARD 1u
#define BACKWARD 2u
#define INIT 3u
#define WAITING 4u
#define PREPARING 5u

#define SWING_X .5f
#define SWING_Y -1.3f

SawingAnimation::SawingAnimation( GLfloat loopT, GLfloat startSawingTime, 
	GLfloat endSawingTime, GLuint swings)
	: Animation(loopT), 
	currentSwingTime(0.f), 
	startSawingTime(startSawingTime),
	state(INIT),
	swing(0),
	sawingTime(endSawingTime - startSawingTime),
	swingTime(sawingTime / (GLfloat)swings),
	goBackwardTime(swingTime / 2.0f),
	forwardSpeed(glm::vec3(SWING_X / swingTime, SWING_Y / sawingTime, 0.f)),
	backwardSpeed(glm::vec3(-SWING_X / swingTime, SWING_Y / sawingTime, 0.f)),
	numberOfSwings(swings)
{
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
