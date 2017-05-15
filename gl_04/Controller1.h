#pragma once
#include <GLFW/glfw3.h> //handles windows creation
#define KEYS 1024

class Controller1
{
public:
	Controller1();
	~Controller1();
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoff, double yoff);
	static void init();
	static bool isKeyPressed(int);
	static GLfloat getMouseXoffset();
	static GLfloat getMouseYoffset();
	static double getScrollOffset();
private:
	static bool* keys;
	static double scrollOffset;
	static bool firstMouse;
	static GLfloat lastX;
	static GLfloat lastY;
	static GLfloat xoffset;
	static GLfloat yoffset;
};
