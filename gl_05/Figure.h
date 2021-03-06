#pragma once
#include <memory>
#include "Shape.h"
#include "Texture.h"
#include "ShaderProgram.h"
#include "Animation.h"

class Figure
{
public:
	Figure(shared_ptr<ShaderProgram>& , shared_ptr<Shape> ,
		shared_ptr<Texture>& , unique_ptr<Animation> anim = unique_ptr<Animation>());
	~Figure();
	glm::mat4 getLocalMat() const;
	virtual void draw(const glm::mat4&) const;
	GLuint getProgramID() const;
	virtual void update(GLfloat);

protected:
	shared_ptr<ShaderProgram> shader;
	shared_ptr<Shape> shape;
	shared_ptr<Texture> texture;
	unique_ptr<Animation> animation;
	glm::mat4 local;
	glm::mat4 startingLocal;
};