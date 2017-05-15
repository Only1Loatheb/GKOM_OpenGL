#include "Figure.h"
Figure::Figure(shared_ptr<ShaderProgram>& program, shared_ptr<Shape>& mesh, shared_ptr<Texture>& tex)
	:shader(program),
	shape(mesh),
	texture(tex),
	local(glm::mat4()),
	startingLocal(local)
{}


Figure::~Figure()
{}


glm::mat4  Figure::getLocalMat() const
{
	return local;
}

void Figure::draw(const glm::mat4& perspective) const
{

	GLuint modelLoc = glGetUniformLocation(getProgramID(), "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(local)); //wrzucamy macierz na karte graficzna do programu szejdera XDDDDDD

	glm::mat4 transform = perspective * local;
	GLuint transformLoc = glGetUniformLocation(getProgramID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, value_ptr(transform)); //wrzucamy macierz na karte graficzna do programu szejdera XDDDDDD

	glm::mat3 inversed = glm::mat3(transpose(inverse(local)));
	GLuint transposedLoc = glGetUniformLocation(getProgramID(), "inversed");
	glUniformMatrix3fv(transposedLoc, 1, GL_FALSE, value_ptr(inversed));

	texture->bind();
	shader->acceptTexture();
	shape->draw();
}

GLuint Figure::getProgramID() const
{
	return shader->getProgramID();
}

void Figure::update(GLfloat)
{}
