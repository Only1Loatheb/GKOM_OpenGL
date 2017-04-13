#include "Timer.h"

Timer::Timer()
	:prevTime(glfwGetTime())
{
}

Timer::~Timer()
{
}

void Timer::update()
{
	double now = glfwGetTime();
	deltaTime = now - prevTime;
	prevTime = now;
}

double Timer::getDeltaTime() const
{
	return deltaTime;
}
