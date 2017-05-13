#pragma once
#include "Camera.h"
#define SCENE_MIN_RADIUS 3 
#define SCENE_MAX_RADIUS 10
#define SCENE_MIN_HEIGHT -5
#define SCENE_MAX_HEIGHT 5
class CircleCamera: public Camera
{
public:
	CircleCamera(GLfloat, GLfloat);
	~CircleCamera();
	void update(GLfloat,std::shared_ptr<ShaderProgram>& program) override;
private:
	glm::vec3 zero;
	GLfloat radius;
	GLfloat height;
	GLfloat rotation;
};

