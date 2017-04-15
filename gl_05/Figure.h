#pragma once
#define GLEW_STATIC
#include "Shape.h"
#include "Texture.h"
#include "shprogram.h"

class Figure
{
public:
	Figure(const GLchar* vertexPath = "figure.vert", const GLchar* fragmentPath = "figure.frag");
	~Figure();
	GLuint get_programID() const;
	glm::mat4 getLocalMat() const;
	void draw() const;
protected:
	ShaderProgram shader;
	Shape shape;
	Texture t0;
	Texture t1;
	GLuint VBO, EBO, VAO;
	const GLchar* v;
	const GLchar* f;
	glm::mat4 local;
};

