#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <stdexcept>

#include <iostream>
class Window
{
public:
	Window(const GLuint,const GLuint, GLFWkeyfun, std::string);
	~Window();
	bool shouldClose();
	void swapBuffers();
	void clearScreen();
private:
	GLFWwindow* window;
};
