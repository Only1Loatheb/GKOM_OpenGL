#include "Window.h"
#include "Controller.h"
#include "Figure.h"
#include "Perspective.h"
#include "CircleCamera.h"
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
		auto c = CircleCamera(10,2);
		Timer t = Timer();
		while (!w.shouldClose())
		{
			w.pollEvents();
			w.clearBuffer();
			t.update();
			c.update(t.getDeltaTime());
			p.update(c.getView(), f);
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
