#pragma once
#include "Figure.h"
class SceneElement :public Figure 
{
public:
	SceneElement(shared_ptr<ShaderProgram>&, shared_ptr<Shape>, shared_ptr<Texture>&);
	~SceneElement();

	void draw(const glm::mat4&) const override;
	void update(GLfloat) override;
};

