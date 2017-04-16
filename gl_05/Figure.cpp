#include "Figure.h"
Figure::Figure(shared_ptr<ShaderProgram>& program , shared_ptr<Shape>& mesh, shared_ptr<Texture>& tex)
:shader(program),
shape(mesh),
texture(tex),
local(glm::mat4())
{}


Figure::~Figure()
{}


glm::mat4  Figure::getLocalMat() const
{
	return local;
}

void Figure::draw() const
{
	texture->bind();
	shader->acceptTexture();
	shader->use();
	shape->draw();
}

GLuint Figure::get_programID() const
{
	return shader->get_programID();
}
