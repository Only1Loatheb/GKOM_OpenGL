#pragma once
#include "Figure.h"
class SceneElement :public Figure 
{
public:
	SceneElement(shared_ptr<ShaderProgram>&, shared_ptr<Shape>, 
		shared_ptr<Texture>&, glm::mat4, unique_ptr<Animation> anim = unique_ptr<Animation>());
	~SceneElement();

	void draw(const glm::mat4&) const override;
};

