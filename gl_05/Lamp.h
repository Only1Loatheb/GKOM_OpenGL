#pragma once
#include "Figure.h"
#include "Controller.h"
class Lamp :public Figure 
{
public:
	Lamp(shared_ptr<ShaderProgram>&, shared_ptr<Shape>, shared_ptr<Texture>&, glm::mat4 );
	~Lamp();
	void draw(const glm::mat4&) const override;
	void update(GLfloat) override;
	void addLightPosToShaders(const std::vector<shared_ptr<ShaderProgram>>&) const;
private:
	GLfloat speed;
	glm::vec3 lightColor;
};

