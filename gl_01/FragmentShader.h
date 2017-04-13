#pragma once
#define GLEW_STATIC
#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class FragmentShader
{
public:
	FragmentShader(const GLchar* fragmentPath);
	~FragmentShader();
	GLuint getFragment();
private:
	GLuint fragment;
};

