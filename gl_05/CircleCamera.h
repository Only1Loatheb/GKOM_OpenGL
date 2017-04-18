#pragma once
#include "Camera.h"
class CircleCamera: public Camera
{
public:
	CircleCamera(GLfloat, GLfloat);
	~CircleCamera();
	void update(GLfloat,std::shared_ptr<ShaderProgram>& program) override;
private:
	glm::vec3 startingPos;
	glm::mat4 rotation;
	GLfloat radius;
	GLfloat height;
};

