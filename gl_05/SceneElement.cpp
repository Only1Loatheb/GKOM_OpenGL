#include "SceneElement.h"



SceneElement::SceneElement(shared_ptr<ShaderProgram>& program, shared_ptr<Shape> mesh, shared_ptr<Texture>& tex)
	:Figure(program, mesh, tex)
{
}


SceneElement::~SceneElement()
{
}

void SceneElement::draw(const glm::mat4 &perspective) const
{
	shader->use();

	GLuint modelLoc = glGetUniformLocation(getProgramID(), "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(local)); //wrzucamy macierz na karte graficzna do programu szejdera XDDDDDD

	glm::mat3 inversed = glm::mat3(transpose(inverse(local)));
	GLuint transposedLoc = glGetUniformLocation(getProgramID(), "inversed");
	glUniformMatrix3fv(transposedLoc, 1, GL_FALSE, value_ptr(inversed));

	Figure::draw(perspective);
}

void SceneElement::update(GLfloat dt)
{
}
