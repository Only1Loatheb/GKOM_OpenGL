#include "Shaders.h"



Shaders::Shaders()
{
	FragmentShader f("TO_DO");
	VertexShader v("TO_DO");
	GLint success;
	GLchar infoLog[512];
	program = glCreateProgram();
	glAttachShader(program, v.getVertex());
	glAttachShader(program, f.getFragment());
	glLinkProgram(program);
	// Print linking errors if any
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

}


Shaders::~Shaders()
{
}

void Shaders::use()
{
	glUseProgram(program);
}
