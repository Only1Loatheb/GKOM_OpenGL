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
	glm::mat4 transform = perspective * local;
	GLuint transformLoc = glGetUniformLocation(getProgramID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, value_ptr(transform)); //wrzucamy macierz na karte graficzna do programu szejdera XDDDDDD

	GLuint localLoc = glGetUniformLocation(getProgramID(), "local");
	glUniformMatrix4fv(localLoc, 1, GL_FALSE, value_ptr(local));


	glm::mat4 inverted = glm::mat4(transpose(inverse(local)));
	GLuint transposedLoc = glGetUniformLocation(getProgramID(), "inverted");
	glUniformMatrix4fv(transposedLoc, 1, GL_FALSE, value_ptr(inverted));

	texture->bind();
	shader->acceptTexture();
	shader->use();
	shape->draw();
}

GLuint Figure::getProgramID() const
{
	return shader->getProgramID();
}

void Figure::update(GLfloat)
{}
