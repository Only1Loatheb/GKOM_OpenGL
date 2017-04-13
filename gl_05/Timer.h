#pragma once
#include <GLFW/glfw3.h>
class Timer
{
public:
	Timer();
	~Timer();
	void update();
	double getDeltaTime() const;
private:
	double prevTime;
	double deltaTime;
};

