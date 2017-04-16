#include <vector>
#include <memory>
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
		auto figureSh = make_shared<ShaderProgram>("figure.vert", "figure.frag");
		auto box = make_shared<Shape>();
		auto weiti = make_shared<Texture>(GL_TEXTURE0, "iipw.png");
		auto figures = std::vector<std::unique_ptr<Figure>>();
		figures.push_back(std::move(std::make_unique<Figure>(figureSh, box, weiti))); //dynamic_cast<Figure>();
		auto perspective = Perspective(WIDTH,HEIGHT);
		auto camera = CircleCamera(10,2);
		//auto camera = FlayingCamera();
		auto timer = Timer();
		while (!window.shouldClose())
		{
			window.pollEvents();
			window.clearBuffer();
			timer.update();
			camera.update(timer.getDeltaTime());
			perspective.update(camera.getView(), figures);
			for (std::unique_ptr<Figure>& f : figures)
				f->draw();
			window.swapBuffers();

		}

	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
