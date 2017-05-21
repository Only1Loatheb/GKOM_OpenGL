#pragma once
#include <GLFW/glfw3.h>

#define KEYS 1024

class Controller
{
public:
	Controller();
	~Controller();
	static void key_callback(GLFWwindow*, int, int, int, int);
	static void init();
	static bool iKBP(int);
private:
	static bool* keys;
};
