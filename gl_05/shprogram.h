#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLEW_STATIC
#include <GL/glew.h>
#include <string>
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