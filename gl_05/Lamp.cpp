#include "Lamp.h"



Lamp::Lamp(shared_ptr<ShaderProgram>& program, shared_ptr<Shape>& mesh, shared_ptr<Texture>& tex)
	:Figure(program, mesh, tex),
	speed(100.0f)
{
	local = glm::translate(local,glm::vec3(-1.2f, -1.0f, -2.0f));
	local = glm::scale(local, glm::vec3(0.2f));
}


Lamp::~Lamp()
{
}

void Lamp::draw(const glm::mat4& perspective) const
{
	glm::vec4 lightPos = local * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);//glm::vec4(lightPosition, 1.0);
	GLint lightPosLoc = glGetUniformLocation(shader->getProgramID(), "lightPos");
	glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);

	GLint lightColorLoc = glGetUniformLocation(shader->getProgramID(), "lightColor");
	glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);

	Figure::draw(perspective);
}

void Lamp::update(GLfloat dt)
{
	glm::vec3 translation;
	GLfloat speed = 10.0f;
	if (Controller::iKBP(GLFW_KEY_O))
		translation.y += dt * speed;
	if (Controller::iKBP(GLFW_KEY_U))
		translation.y -= dt * speed;
	if (Controller::iKBP(GLFW_KEY_K))
		translation.x += dt * speed;
	if (Controller::iKBP(GLFW_KEY_I))
		translation.x -= dt * speed;
	if (Controller::iKBP(GLFW_KEY_J))
		translation.z += dt * speed;
	if (Controller::iKBP(GLFW_KEY_L))
		translation.z -= dt * speed;
	local = glm::translate(local, translation);
}
