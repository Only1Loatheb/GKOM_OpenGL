#include "Window.h"
#include "Controller.h"
#include "Figure.h"
#include "Perspective.h"
#include "Camera.h"
#include "Timer.h"
static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

int main()
{
	try
	{
		Window w(WIDTH, HEIGHT, &Controller::key_callback, "moje okienko <3");		
		Figure f = Figure();
		Perspective p = Perspective(WIDTH,HEIGHT);
		Camera c = Camera();
		Timer t = Timer();
		while (!w.shouldClose())
		{
			w.pollEvents();
			w.clearScreen();
			c.update(t.getDeltaTime());
			p.update(0.10f, f);
			f.Draw();
			w.swapBuffers();
			t.update();
		}

	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}
