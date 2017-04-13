#include "Window.h"
#include "Controller.h"
#include "Figure.h"
#include "Perspective.h"
static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

int main()
{
	try
	{
		Window w(WIDTH, HEIGHT, &Controller::key_callback, "moje okienko <3");		
		Figure f = Figure();
		Perspective p = Perspective();
		while (!w.shouldClose())
		{
			w.pollEvents();
			w.clearScreen();
			p.update(0.10f, f);
			f.Draw();
			w.swapBuffers();
		}

	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}
