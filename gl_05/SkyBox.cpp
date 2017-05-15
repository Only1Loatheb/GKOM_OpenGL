#include "SkyBox.h"

SkyBox::SkyBox(shared_ptr<ShaderProgram>& program, shared_ptr<Shape> mesh, 
	shared_ptr<Texture>& tex, GLfloat maxr)
	:SceneElement(program, mesh, tex)
{
	local = glm::scale(local, glm::vec3(maxr*2));
}

SkyBox::~SkyBox()
{
}
