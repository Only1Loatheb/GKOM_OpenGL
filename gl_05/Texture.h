#pragma once
#include <stdexcept>
#include <GL/glew.h>
#include <SOIL.h>

class Texture
{
public:
	Texture(GLuint , const char*);
	~Texture();
	void bind()const;
	GLuint getTexID()const;
private:
	GLuint texture;
	GLuint texId;
	int width, height;
};

