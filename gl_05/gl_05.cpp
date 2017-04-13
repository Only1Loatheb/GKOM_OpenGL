#include <vector>
#include "Window.h"
#include "Controller.h"
#include "Figure.h"
#include "Perspective.h"
#include "CircleCamera.h"
#include "FlayingCamera.h"
#include "Timer.h"
static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

int main()
{
	try
	{
		Controller::init();
		Window window(WIDTH, HEIGHT, &Controller::key_callback, "moje okienko <3");		
		std::vector<Figure> figures = std::vector<Figure>();
		figures.push_back(Figure());
		Perspective perspective = Perspective(WIDTH,HEIGHT);
		//auto c = CircleCamera(10,2);
		auto camera = FlayingCamera();
		Timer timer = Timer();
		while (!window.shouldClose())
		{
			window.pollEvents();
			window.clearBuffer();
			timer.update();
			camera.update(timer.getDeltaTime());
			perspective.update(camera.getView(), figures);
			for (Figure f : figures)
			{
				f.draw();
			}
			window.swapBuffers();

		}

	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
