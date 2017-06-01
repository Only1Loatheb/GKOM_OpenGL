#include "Lamp.h"



Lamp::Lamp(shared_ptr<ShaderProgram>& program, shared_ptr<Shape> mesh, shared_ptr<Texture>& tex, glm::mat4 l)
	:Figure(program, mesh, tex),
	speed(100.0f),
	lightColor(glm::vec3(1.0f, 1.0f, 1.0f))
{
	local = l;
}


Lamp::~Lamp()
{
}

void Lamp::draw(const glm::mat4& perspective) const
{
	shader->use();
	Figure::draw(perspective);
}

void Lamp::update(GLfloat dt)
{
	glm::vec3 translation(.0f);
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

void Lamp::addLightPosToShaders( const std::vector<shared_ptr<ShaderProgram>>& programsToSetPos) const
{
	for (const shared_ptr<ShaderProgram>& p : programsToSetPos)
	{
		glm::vec4 lightPos = local * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);//glm::vec4(lightPosition, 1.0);
		GLint lightPosLoc = glGetUniformLocation(p->getProgramID(), "lightPos");
		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);

		GLint lightColorLoc = glGetUniformLocation(p->getProgramID(), "lightColor");
		glUniform3f(lightColorLoc, lightColor.r, lightColor.g, lightColor.b);
	}
}