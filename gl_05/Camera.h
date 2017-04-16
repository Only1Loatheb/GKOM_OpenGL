#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "Controller.h"
class Camera
{
public:
	Camera();
	~Camera();
	const glm::mat4& getView() const;
	virtual void update(GLfloat dt) = 0;
protected:
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 up;
	glm::vec3 cameraRight;
	glm::vec3 cameraUp;
	glm::mat4 view;
};

