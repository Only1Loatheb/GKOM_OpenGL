#include "Figure.h"
Figure::Figure(shared_ptr<ShaderProgram>& program, shared_ptr<Shape> mesh, 
	shared_ptr<Texture>& tex, unique_ptr<Animation> anim)
	:shader(program),
	shape(mesh),
	texture(tex),
	animation(std::move(anim)),
	local(glm::mat4()),
	startingLocal(local)
{}


Figure::~Figure()
{}


glm::mat4  Figure::getLocalMat() const
{
	return local;
}

void Figure::draw(const glm::mat4& perspective) const
{	
	glm::mat4 transform = perspective * local;
	GLuint transformLoc = glGetUniformLocation(getProgramID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, value_ptr(transform)); //wrzucamy macierz na karte graficzna do programu szejdera XDDDDDD

	texture->bind();
	shader->acceptTexture();
	shape->draw();
}

GLuint Figure::getProgramID() const
{
	return shader->getProgramID();
}

void Figure::update(GLfloat dt)
{	
	if (animation) 
	{
		animation->animate(local, dt);
	}
}
