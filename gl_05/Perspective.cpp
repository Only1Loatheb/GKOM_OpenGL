#include "Perspective.h"

Perspective::Perspective(GLuint width, GLuint height)
{
	proj = glm::perspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
	model = glm::rotate(model, -55.0f, glm::vec3(1.0f, 0.0f, 0.0f));
}

Perspective::~Perspective()
{
}

void Perspective::update(const glm::mat4 view, std::vector<Figure>& figures)
{
	for (Figure f : figures)
	{
		glm::mat4 trans = proj * view * model * f.getLocalMat();
		GLuint transformLoc = glGetUniformLocation(f.get_programID(), "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, value_ptr(trans)); //wrzucamy macierz na karte graficzna do programu szejdera XDDDDDD
	}
}

