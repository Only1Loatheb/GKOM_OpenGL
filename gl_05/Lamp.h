#pragma once
#include "Figure.h"
#include "Controller.h"
class Lamp :public Figure 
{
public:
	Lamp(shared_ptr<ShaderProgram>&, shared_ptr<Shape>&, shared_ptr<Texture>&);
	~Lamp();
	void draw(const glm::mat4&) const override;
	void update(GLfloat) override;
private:
	GLfloat speed;
};

