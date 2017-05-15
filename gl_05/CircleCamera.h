#pragma once
#include "Camera.h"

class CircleCamera: public Camera
{
public:
	CircleCamera(GLfloat r, GLfloat h,GLfloat minR, GLfloat maxR,GLfloat minH,
	GLfloat maxH);
	~CircleCamera();
	void update(GLfloat,std::shared_ptr<ShaderProgram>& program) override;
private:
	glm::vec3 zero;
	GLfloat radius;
	GLfloat height;
	GLfloat rotation;
	const GLfloat minR;
	const GLfloat maxR;
	const GLfloat minH;
	const GLfloat maxH;
};

