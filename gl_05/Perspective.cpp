#include "Perspective.h"

Perspective::Perspective(GLuint width, GLuint height)
{
	trans = glm::mat4();
	rot_angle = 0.0f;

	proj = glm::perspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
	model = glm::rotate(model, -55.0f, glm::vec3(1.0f, 0.0f, 0.0f));
}

Perspective::~Perspective()
{
}


const GLfloat * Perspective::getTrans()
{
	return glm::value_ptr(trans);
}

void Perspective::update(const glm::mat4 view,const Figure& f)
{
	trans = proj * view * model * f.getLocalMat();
	GLuint transformLoc = glGetUniformLocation(f.get_programID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, getTrans()); //wrzucamy macierz na karte graficzna do programu szejdera XDDDDDD

}

ostream & operator<<(ostream & os, const glm::mat4 & mx)
{
	glm::mat4 trans;
	std::cout << trans << std::endl;
	//							kat w radianach			os obrotu z 2 punktow (os "z")
	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	std::cout << trans << std::endl;
	return os;
}

