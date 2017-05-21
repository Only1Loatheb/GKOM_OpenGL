#pragma once
#define GLEW_STATIC
#include <stdexcept>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(const GLuint,const GLuint, GLFWkeyfun, std::string);
	~Window();
	bool shouldClose() const;
	void clearBuffer() const;
	void pollEvents() const;
	void swapBuffers() const;
private:
	GLFWwindow* window;
};
