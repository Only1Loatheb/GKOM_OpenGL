#include <iostream>
#include <stdexcept>

#include "Window.h"
#include "Controller.h"
#include "Mesh.h"
//#include "saw1.h"
#include "Shaders.h"

static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

int main()
{
	try
	{
		GLfloat deltaTime = 0.0f;
		GLfloat lastFrame = glfwGetTime();

		Controller c;
		Window w(WIDTH, HEIGHT, Controller::key_callback, std::string("moje okienko <3"));
		//Saw1 saw;
		//Mesh sawMesh(saw.vertices, saw.numVertices, saw.indices, saw.numIndices);
		Shaders s;
		// main loop
		while (!w.shouldClose())
		{
			GLfloat currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			glfwPollEvents();
			w.clearScreen();
			s.use();
			//sawMesh.draw();

			w.swapBuffers();
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	glfwTerminate();
	return 0;
}
/* 					  // Set the texture wrapping parameters
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// Set texture filtering parameters
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
*/
