#include "Controller1.h"

bool* Controller1::keys = new bool[1024];
double Controller1::scrollOffset = 0.0f;
GLfloat Controller1::xoffset = 0.0f;
GLfloat Controller1::yoffset = 0.0f;
GLfloat Controller1::lastX = 400;
GLfloat Controller1::lastY = 300;


Controller1::Controller1()
{
}


Controller1::~Controller1()
{
}

void Controller1::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < KEYS)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

void Controller1::mouse_callback(GLFWwindow * window, double xpos, double ypos)
{
		xoffset = xpos - lastX;
		yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left

		lastX = xpos;
		lastY = ypos;
}

void Controller1::scroll_callback(GLFWwindow * window, double xoff, double yoff)
{
	scrollOffset = yoff;
}

void Controller1::init()
{
	for (int i = 0; i < KEYS; ++i)
	{
		keys[i] = false;
	}
}

bool Controller1::isKeyPressed(int i)
{
	return keys[i];
}

GLfloat Controller1::getMouseXoffset()
{
	return xoffset;
}

GLfloat Controller1::getMouseYoffset()
{
	return yoffset;
}

double Controller1::getScrollOffset()
{
	return scrollOffset;
}
