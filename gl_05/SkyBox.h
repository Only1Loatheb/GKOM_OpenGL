#pragma once
#include "SceneElement.h"
class SkyBox :public SceneElement
{
public:
	SkyBox(shared_ptr<ShaderProgram>&, shared_ptr<Shape>, 
		shared_ptr<Texture>&,GLfloat);
	~SkyBox();
};

