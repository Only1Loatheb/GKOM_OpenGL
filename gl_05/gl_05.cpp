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
#include "SceneElement.h"
#include "Box.h"

static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;
static const GLfloat MIN_RADIUS = 3.0f;
static const GLfloat MAX_RADIUS = 10.0f;
static const GLfloat MIN_HEIGHT = 0.0f;
static const GLfloat MAX_HEIGHT = 5.0f;

int main()
{
	try
	{
		Controller::init();
		Window window(WIDTH, HEIGHT, &Controller::key_callback, "moje okienko <3");
		auto basicShader = make_shared<ShaderProgram>("basic.vert", "basic.frag");
		auto shadersWithLight = std::vector<std::shared_ptr<ShaderProgram>>();
		auto sceneShader = make_shared<ShaderProgram>("figure.vert", "figure.frag");
		shadersWithLight.push_back(sceneShader);
		auto box = make_shared<Box>();
		auto weiti = make_shared<Texture>(GL_TEXTURE0, "white.png");
		auto metal = make_shared<Texture>(GL_TEXTURE0, "metal.png");
		auto sky = make_shared<Texture>(GL_TEXTURE0, "skybox.jpg");
		auto sceneElements = std::vector<std::unique_ptr<SceneElement>>();
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(basicShader, box, sky, 
			glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 10.0f, 0.0f)), glm::vec3(MAX_RADIUS * 2)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal, 
			glm::scale(glm::translate(glm::mat4(), glm::vec3(1.2f, 1.0f, 2.0f)), glm::vec3(0.2f, 2.0f, 0.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal, 
			glm::scale(glm::translate(glm::mat4(), glm::vec3(1.2f, 1.0f, -2.0f)), glm::vec3(0.2f, 2.0f, 0.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(-1.2f, 1.0f, 2.0f)), glm::vec3(0.2f, 2.0f, 0.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(-1.2f, 1.0f, -2.0f)), glm::vec3(0.2f, 2.0f, 0.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 2.0f-0.1f, 2.0f)), glm::vec3(2.2f, 0.2f, 0.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 2.0f-0.1f, -2.0f)), glm::vec3(2.2f, 0.2f, 0.2f)))));
		auto lamp = make_unique<Lamp>(basicShader, box, weiti,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(-1.5f, 2.0f, -1.5f)), glm::vec3(0.2f)));
		auto perspective = Perspective(WIDTH,HEIGHT);
		auto camera = CircleCamera(5,2,MIN_RADIUS,MAX_RADIUS,MIN_HEIGHT,MAX_HEIGHT);
		//auto camera = FlayingCamera();
		auto timer = Timer();

		while (!window.shouldClose())
		{
			window.pollEvents();
			window.clearBuffer();
			timer.update();
			camera.update(timer.getDeltaTime(),sceneShader);
			lamp->update(timer.getDeltaTime());
			lamp->addLightPosToShaders(shadersWithLight);
			lamp->draw(perspective.getTrans(camera.getView()));
			for (std::unique_ptr<SceneElement>& f : sceneElements)
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
		int i;
		std::cin >> i;
	}
	return 0;
}
