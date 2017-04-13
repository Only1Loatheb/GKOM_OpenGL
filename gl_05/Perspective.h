#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
using namespace std;
#include "Figure.h"

class Perspective
{
public:
	Perspective();
	~Perspective();	
	void update(GLfloat time, Figure&);
private:
	const GLfloat* getTrans();
	glm::mat4 trans;
	GLfloat rot_angle;
};
ostream& operator<<(ostream& os, const glm::mat4& mx);
/*	biblioteka do macierzy przyk³ad
glm::mat4 trans;
cout << trans << endl;
//							kat w radianach			os obrotu z 2 punktow (os "z")
trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
cout << trans << endl;
	}
*/