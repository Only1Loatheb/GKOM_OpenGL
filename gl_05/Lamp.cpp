#include "Lamp.h"



Lamp::Lamp(shared_ptr<ShaderProgram>& program, shared_ptr<Shape>& mesh, shared_ptr<Texture>& tex)
	:Figure(program, mesh, tex)
{
	auto lightPos = glm::vec3(-1.2f, -1.0f, -2.0f);
	local = glm::translate(local, lightPos);
	local = glm::scale(local, glm::vec3(0.2f));
	GLint lightPosLoc = glGetUniformLocation(program->getProgramID(), "lightPos");
	glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
}


Lamp::~Lamp()
{
}
