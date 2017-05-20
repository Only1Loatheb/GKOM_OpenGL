#include "SplitingAnimation.h"

SplitingAnimation::SplitingAnimation( GLfloat loopT,GLfloat start, GLboolean side)
	:Animation( loopT), startFallingTime(start)
{
	state = INIT;
	fallingTime = loopT - start;
	theta = 90.f/ fallingTime;
	translation = glm::vec3(0.2f / fallingTime,1.f / fallingTime, 0.f);
	if (side)
	{
		translation = glm::vec3(- 0.2f /fallingTime, 1.f / fallingTime , 0.f);
		theta = -theta;
	}
	rotateAround = glm::vec3(0.f, 0.f, 1.f);
}

SplitingAnimation::~SplitingAnimation()
{
}

void SplitingAnimation::animate(glm::mat4 & local, GLfloat dt)
{
	currentTime += dt;
	if (state == FALLING)
	{
		local = glm::rotate(local, glm::radians(theta * dt ) , rotateAround);
		local = glm::translate(local, translation * dt);
		if (currentTime > loopTime)
		{
			local = startingLocal;
			currentTime = 0.f;
			state = WAITING;
		}
		return;
	}
	else if (state == WAITING)
	{
		if (currentTime > startFallingTime)
		{
			state = FALLING;
		}
		return;
	}
	else if (state == INIT)
	{
		startingLocal = local;;
		state = WAITING;
		return;
	}
}
