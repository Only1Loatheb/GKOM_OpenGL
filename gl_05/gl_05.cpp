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
#include "SawBlade.h"
#include "HalfLog.h"
#include "Sphere.h"
#include "Cylinder.h"

static const GLuint WIDTH = 1920;
static const GLuint HEIGHT = 1080;
static const GLfloat MIN_RADIUS = 3.0f;
static const GLfloat MAX_RADIUS = 10.0f;
static const GLfloat MIN_HEIGHT = 0.1f;
static const GLfloat MAX_HEIGHT = 5.0f;

int main()
{
	try
	{
		Controller::init();
		Window window(WIDTH, HEIGHT, &Controller::key_callback, "moje okienko <3");
		//shaders
		auto basicShader = make_shared<ShaderProgram>("basic.vert", "basic.frag");
		auto shadersWithLight = std::vector<std::shared_ptr<ShaderProgram>>();
		auto sceneShader = make_shared<ShaderProgram>("figure.vert", "figure.frag");
		shadersWithLight.push_back(sceneShader);
		//shapes
		auto box = make_shared<Box>(1.0f);
		auto saw = make_shared<SawBlade>(4.0f,50,0.05f,0.1f,0.02f);
		auto log = make_shared<HalfLog>(0.5f,3.f,20,0.5f);
		auto ball = make_shared<Sphere>(1.0f, 20, 20);
		auto cylinder = make_shared<Cylinder>(0.5f, 3.0f,20);
		//textures
		auto weiti = make_shared<Texture>(GL_TEXTURE0, "white.png");
		auto metal = make_shared<Texture>(GL_TEXTURE0, "metal.png");
		auto sky = make_shared<Texture>(GL_TEXTURE0, "skybox.jpg");
		auto wood = make_shared<Texture>(GL_TEXTURE0, "wood.jpg");
		//light
		auto lamp = make_unique<Lamp>(basicShader, ball, weiti,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(-1.5f, 2.0f, -1.5f)), glm::vec3(0.2f)));
		auto sceneElements = std::vector<std::unique_ptr<SceneElement>>();
		//skybox
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(basicShader, box, sky, 
			glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 10.0f, 0.0f)), glm::vec3(MAX_RADIUS * 2)))));
		//pilars
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal, 
			glm::scale(glm::translate(glm::mat4(), glm::vec3(2.0f, 1.0f, 1.2f)), glm::vec3(0.2f, 2.0f, 0.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal, 
			glm::scale(glm::translate(glm::mat4(), glm::vec3(2.0f, 1.0f, -1.2f)), glm::vec3(0.2f, 2.0f, 0.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(-2.0f, 1.0f, 1.2f)), glm::vec3(0.2f, 2.0f, 0.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(-2.0f, 1.0f, -1.2f)), glm::vec3(0.2f, 2.0f, 0.2f)))));
		//beams
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(2.0f, 2.0f-0.1f, 0.0f)), glm::vec3(0.2f, 0.2f, 2.2f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(-2.0f, 2.0f-0.1f, 0.0f)), glm::vec3(0.2f, 0.2f, 2.2f)))));
		//saw
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, box, metal,
			glm::scale(glm::translate(glm::mat4(), glm::vec3(.0f, 2.0f - 0.1f, .0f)), glm::vec3(4.f, 0.2f, 0.1f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, saw, metal, 
			glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 2.0f-0.2f, 0.0f)), glm::vec3(1.0f)))));
		//logs
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, log, wood,
			glm::rotate(glm::rotate(glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 1.0f, 0.0f)), glm::vec3(1.0f)), glm::radians(90.f), glm::vec3(1.f, .0f, 0.f)), glm::radians(90.f), glm::vec3(.0f, 1.f, 0.f)))));
		sceneElements.push_back(std::move(std::make_unique<SceneElement>(sceneShader, log, wood,
			glm::rotate(glm::rotate(glm::scale(glm::translate(glm::mat4(), glm::vec3(0.0f, 1.0f, 0.0f)), glm::vec3(1.0f)), glm::radians(90.f), glm::vec3(-1.f, .0f, 0.f)), glm::radians(90.f), glm::vec3(.0f, 1.f, 0.f)))));
		//utilities
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
