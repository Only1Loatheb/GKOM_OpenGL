#include "Controller.h"

bool* Controller::keys = new bool[1024];

Controller::Controller()
{
}


Controller::~Controller()
{
}

void Controller::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

bool Controller::iKBP(int i)
{
	return keys[i];
}
