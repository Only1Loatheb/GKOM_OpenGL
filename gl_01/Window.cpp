#include "Window.h"

Window::Window(const GLuint width, const GLuint height, GLFWkeyfun kay_callback, std::string name)
{
	if (glfwInit() != GL_TRUE)
	{
		throw std::exception("GLFW initialization failed");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(width, height, name.data(), nullptr, nullptr);
	if (window == nullptr)
	{
		throw std::exception("GLFW window not created");
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, kay_callback);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw std::exception("GLEW Initialization failed");

	glViewport(0, 0, width, width); //area of window avalible for openGl
	glEnable(GL_DEPTH_TEST);
}


Window::~Window()
{
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}
void Window::swapBuffers()
{
	glfwSwapBuffers(window);
}
void Window::clearScreen()
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
