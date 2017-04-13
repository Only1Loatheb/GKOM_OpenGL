#pragma once
#include <GL/glew.h>
#include <iostream>

#include "FragmentShader.h"
#include "VertexShader.h"

class Shaders
{
public:
	Shaders();
	~Shaders();
	void use();
private:
	GLuint program;
};

