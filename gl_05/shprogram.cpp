#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	// prepare vertex and fragment shaders
	string vertex_code = readShaderCode(vertexPath);
	GLuint vertex_id = compileShader(vertex_code.c_str(), GL_VERTEX_SHADER);

	string fragment_code = readShaderCode(fragmentPath);
	GLuint fragment_id = compileShader(fragment_code.c_str(), GL_FRAGMENT_SHADER);

	// link shader program
	programID = glCreateProgram();
	glAttachShader(programID, vertex_id);
	glAttachShader(programID, fragment_id);
	glLinkProgram(programID);

	// Print linking errors if any
	GLint success;
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetProgramInfoLog(programID, sizeof(infoLog), NULL, infoLog);
		string msg = string("Shader program linking: ") + infoLog;
		throw exception(msg.c_str());
	}

	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex_id);
	glDeleteShader(fragment_id);
}

string ShaderProgram::readShaderCode(const GLchar* shaderPath)
{
	ifstream shader_file;
	shader_file.exceptions(ifstream::badbit);

	shader_file.open(shaderPath);
	stringstream shader_stream;
	shader_stream << shader_file.rdbuf();
	shader_file.close();
	return shader_stream.str();
}

GLuint ShaderProgram::compileShader(const GLchar* shaderCode, GLenum shaderType)
{
	GLuint shader_id = glCreateShader(shaderType);
	glShaderSource(shader_id, 1, &shaderCode, NULL);
	glCompileShader(shader_id);

	// Print compile errors if any
	GLint success = 0;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(shader_id, sizeof(infoLog), NULL, infoLog);
		string msg = string("Shader compilation: ") + infoLog;
		throw exception(msg.c_str());
	}
	return shader_id;
}

void ShaderProgram::use() const
{
	glUseProgram(programID);
}

GLuint ShaderProgram::getProgramID() const
{
	return programID;
}

void ShaderProgram::acceptTexture() const
{
	glUniform1i(glGetUniformLocation(programID, "Texture0"),0);
}
