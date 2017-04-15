#include "Window.h"

Window::Window(const GLuint width, const GLuint height, GLFWkeyfun kay_callback, std::string name)
{
	if (glfwInit() != GL_TRUE)
		throw std::exception("GLFW Initialization failed");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(width, height, name.data(), nullptr, nullptr);
	if (window == nullptr)
		throw std::exception("GLFW window not created");
	
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, kay_callback);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw std::exception("GLEW Initialization failed");

	glViewport(0, 0, width, height);
}


Window::~Window()
{
	glfwTerminate();
}

void Window::clearBuffer() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::pollEvents() const
{
	glfwPollEvents();
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(window);
}

void Window::swapBuffers() const
{
	glfwSwapBuffers(window);
}
