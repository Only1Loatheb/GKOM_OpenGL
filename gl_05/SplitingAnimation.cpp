#include "SplitingAnimation.h"
#include <glm/gtc/matrix_transform.hpp>

#define INIT 1u
#define WAITING 2u
#define FALLING 3u
#define LAYING  4u

SplitingAnimation::SplitingAnimation( GLfloat loopT,GLfloat start, GLfloat end, GLboolean side)
	:Animation( loopT), startFallingTime(start), endFalingTime(end)
{
	state = INIT;
	fallingTime =  end - start;
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
	if (state == LAYING)
	{
		if (currentTime > loopTime)
		{
			local = startingLocal;
			currentTime = 0.f;
			state = WAITING;
		}
		return;
	}
	else if (state == FALLING)
	{
		local = glm::rotate(local, glm::radians(theta * dt ) , rotateAround);
		local = glm::translate(local, translation * dt);
		if (currentTime > endFalingTime)
		{
			state = LAYING;
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
