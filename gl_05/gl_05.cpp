#include <vector>
#include <memory>
#include "Window.h"
#include "Controller.h"
#include "Perspective.h"
#include "Timer.h"
#include "CircleCamera.h"
#include "FlayingCamera.h"
#include "Figure.h"
#include "Lamp.h"
static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

int main()
{
	try
	{
		Controller::init();
		Window window(WIDTH, HEIGHT, &Controller::key_callback, "moje okienko <3");		
		auto figureSh = make_shared<ShaderProgram>("figure.vert", "figure.frag");
		auto box = make_shared<Shape>();
		auto weiti = make_shared<Texture>(GL_TEXTURE0, "weiti.png");
		auto metal = make_shared<Texture>(GL_TEXTURE0, "metal.png");
		auto figures = std::vector<std::unique_ptr<Figure>>();
		figures.push_back(std::move(std::make_unique<Figure>(figureSh, box, metal))); //dynamic_cast<Figure>();
		figures.push_back(std::move(std::make_unique<Lamp>(figureSh, box, weiti))); //dynamic_cast<Figure>();
		auto perspective = Perspective(WIDTH,HEIGHT);
		//auto camera = CircleCamera(10,2);
		auto camera = FlayingCamera();
		auto timer = Timer();
		while (!window.shouldClose())
		{
			window.pollEvents();
			window.clearBuffer();
			timer.update();
			camera.update(timer.getDeltaTime());
			for (std::unique_ptr<Figure>& f : figures)
			{
				f->update( timer.getDeltaTime());
				f->draw(perspective.getTrans(camera.getView()));
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
