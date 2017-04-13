#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Controller
{
public:
	Controller();
	~Controller();
	static void key_callback(GLFWwindow*, int, int, int, int);
	static bool iKBP(int) ;
private:
	static bool* keys;
};
