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
	GLuint get_programID() const;
private:
	GLuint program_id; 	// The program ID
	std::string read_shader_code(const GLchar*);
	GLuint compile_shader(const GLchar*, GLenum);
};