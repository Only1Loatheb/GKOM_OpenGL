#pragma once
#include "Figure.h"
class Lamp :public Figure 
{
public:
	Lamp(shared_ptr<ShaderProgram>&, shared_ptr<Shape>&, shared_ptr<Texture>&);
	~Lamp();
};

