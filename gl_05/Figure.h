#pragma once
#define GLEW_STATIC
#include <memory>
#include "Shape.h"
#include "Texture.h"
#include "shprogram.h"

class Figure
{
public:
	Figure(shared_ptr<ShaderProgram>& , shared_ptr<Shape>& , shared_ptr<Texture>& );
	~Figure();
	glm::mat4 getLocalMat() const;
	void draw(const glm::mat4&) const;
	GLuint getProgramID() const;
	void update( GLfloat);
protected:
	shared_ptr<ShaderProgram> shader;
	shared_ptr<Shape> shape;
	shared_ptr<Texture> texture;
	glm::mat4 local;
};