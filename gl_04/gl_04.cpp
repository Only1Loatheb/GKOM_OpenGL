#define GLEW_STATIC
#include <GL/glew.h>
#include "shprogram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
using namespace std;

const GLuint WIDTH = 800, HEIGHT = 600;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	cout << key << endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
	if (glfwInit() != GL_TRUE)
	{
		cout << "GLFW initialization failed" << endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	try
	{
		GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GKOM - OpenGL 04", nullptr, nullptr);
		if (window == nullptr)
			throw exception("GLFW window not created");
		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, key_callback);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw exception("GLEW Initialization failed");

		glViewport(0, 0, WIDTH, HEIGHT);

		// Let's check what are maximum parameters counts
		GLint nrAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
		cout << "Max vertex attributes allowed: " << nrAttributes << std::endl;
		glGetIntegerv(GL_MAX_TEXTURE_COORDS, &nrAttributes);
		cout << "Max texture coords allowed: " << nrAttributes << std::endl;

		// Build, compile and link shader program
		ShaderProgram theProgram("gl_04.vert", "gl_04.frag");

		// Set up vertex data 
		GLfloat vertices[] = {
			// coordinates			// color			// texture
			 0.25f,  0.5f,  0.0f,	1.0f, 0.0f, 0.0f,	2.f,  0.0f,	
			-0.75f,  0.5f,  0.0f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,
			-0.25f, -0.5f,  0.0f,	0.0f, 0.0f, 1.0f,	0.0f,  2.f,
			 0.75f, -0.5f,  0.0f,	1.0f, 0.0f, 1.0f,	2.f,  2.f,
		};/*ktore miejsce tekstury ma byc zamapowane na pixel 
			* normalizacja rozmiarow tekstury <0,1> 
			* tekstura jest powtarzana okresowo "nie sam xD"
			*/
		//dablica indexów do wierzcholkow 
		GLuint indices[] = {
			//1w //2w //3w
			0,	1,	2,		//trojkat 1
			0,	2,	3,		//trojkat 2
		};

		GLuint VBO, EBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//to GPU \m/

		// vertex geometry data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		// vertex color data
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		// vertex texture coordinates//tu jest ze dwa floaty
		glVertexAttribPointer(2, 2/*tuuuu*/, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

		glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

		// Set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// Set texture filtering parameters //kilka pixeli textury (texeli) wpada w jeden pixel obrazu
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		/*obrazy wielowymiarowe jak jedno wymiarowe sygna³y mozna filtrowac ,szczegoly == wysokie czestotliwosci*/
		// prepare textures
		int width, height;//wiersz textury powinien miec rozmiar podzielny przez 4 // tu dostajemy w i h
		unsigned char* image = SOIL_load_image("iipw.png", &width, &height, 0, SOIL_LOAD_RGB); //wczytywanie fextury 
		if (image == nullptr)
			throw exception("Failed to load texture file");

		GLuint texture0;//identyfikator 
		glGenTextures(1, &texture0);

		glActiveTexture(GL_TEXTURE0); //jednostka teksturujaca pogchamp, jest ich 96 min, gl 3.3 ~30
		glBindTexture(GL_TEXTURE_2D, texture0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image); //dane dla textury narszcie
		glGenerateMipmap(GL_TEXTURE_2D); // ta fcja generuje mniejsze wersje textury (mid_map)(3D tez sa)
		// freeing unnecessary texture stuff
		SOIL_free_image_data(image);
		glBindTexture(GL_TEXTURE_2D, 0);

		/*copy pasta*/
		int width1, height1;//wiersz textury powinien miec rozmiar podzielny przez 4 // tu dostajemy w i h
		unsigned char* image1 = SOIL_load_image("weiti.png", &width1, &height1, 0, SOIL_LOAD_RGB); //wczytywanie fextury 
		if (image1 == nullptr)
			throw exception("Failed to load texture file");

		GLuint texture1;//identyfikator 
		glGenTextures(1, &texture1);

		glActiveTexture(GL_TEXTURE1); //jednostka teksturujaca pogchamp, jest ich 96 min, gl 3.3 ~30
		glBindTexture(GL_TEXTURE_2D, texture1);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB, GL_UNSIGNED_BYTE, image1); //dane dla textury narszcie
		glGenerateMipmap(GL_TEXTURE_2D); // ta fcja generuje mniejsze wersje textury (mid_map)(3D tez sa)
		// freeing unnecessary texture stuff
		SOIL_free_image_data(image1);
		glBindTexture(GL_TEXTURE_2D, 0);
		/*copy pasta*/

		// main event loop
		while (!glfwWindowShouldClose(window))
		{
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Clear the colorbuffer
			glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// Bind Textures using texture units
			glActiveTexture(GL_TEXTURE0);			//| lokalizacja zmiennej
			glBindTexture(GL_TEXTURE_2D, texture0); //V  
			glUniform1i(glGetUniformLocation(theProgram.get_programID(), "Texture0"), 0);
		
			glActiveTexture(GL_TEXTURE1);			//| lokalizacja zmiennej
			glBindTexture(GL_TEXTURE_2D, texture1); //V  
			glUniform1i(glGetUniformLocation(theProgram.get_programID(), "Texture1"), 1);

			//zmienne uniform robia cos z shaderem to takie globalne dla nich
			// Draw our first triangle
			theProgram.Use();

			glBindVertexArray(VAO);
			cout << _countof(indices) << endl;
			glDrawElements(GL_TRIANGLES, _countof(indices), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			// Swap the screen buffers
			glfwSwapBuffers(window);
		}
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	glfwTerminate();

	return 0;
}
