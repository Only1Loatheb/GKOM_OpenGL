#include "Lamp.h"



Lamp::Lamp(shared_ptr<ShaderProgram>& program, shared_ptr<Shape>& mesh, shared_ptr<Texture>& tex)
	:Figure(program, mesh, tex)
{
}


Lamp::~Lamp()
{
}
