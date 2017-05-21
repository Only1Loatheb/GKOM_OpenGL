#pragma once
#define GLEW_STATIC
#include <string>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
using namespace std;
class ShaderProgram
{
public:
	ShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath);
	void use() const;
	GLuint getProgramID() const;
	void acceptTexture() const;
private:
	GLuint programID; 	// The program ID
	std::string readShaderCode(const GLchar*);
	GLuint compileShader(const GLchar*, GLenum);
};