#pragma once
#define GLEW_STATIC
#include <memory>
#include "Shape.h"
#include "Texture.h"
#include "shprogram.h"
//shared_ptr<ShaderProgram>& program , shared_ptr<Shape>& mesh, shared_ptr<Texture>& tex
//t0(make_shared<Texture>(GL_TEXTURE0, "iipw.png")),
class Figure
{
public:
	Figure(shared_ptr<ShaderProgram>& , shared_ptr<Shape>& , shared_ptr<Texture>& );
	~Figure();
	glm::mat4 getLocalMat() const;
	void draw() const;
	GLuint get_programID() const;
protected:
	shared_ptr<ShaderProgram> shader;
	shared_ptr<Shape> shape;
	shared_ptr<Texture> texture;
	glm::mat4 local;
};

