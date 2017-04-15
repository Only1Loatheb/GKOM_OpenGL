#include "Figure.h"
Figure::Figure()
:shader(ShaderProgram("gl_05.vert", "gl_05.frag")),
shape(Shape()),
t0(Texture(GL_TEXTURE0, "iipw.png")),
t1(Texture(GL_TEXTURE1, "weiti.png")),
local(glm::mat4())
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, shape.sizeofVertices(), shape.getVertices(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, shape.sizeofIndices(), shape.getIndices(), GL_STATIC_DRAW);

	// vertex geometry data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// vertex color data
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// vertex texture coordinates
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
}


Figure::~Figure()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

GLuint Figure::get_programID() const
{
	return shader.get_programID();
}

glm::mat4  Figure::getLocalMat() const
{
	return local;
}

void Figure::draw() const
{
	t0.bind();
	glUniform1i(glGetUniformLocation(get_programID(), "Texture0"), 0);
	t1.bind();
	glUniform1i(glGetUniformLocation(get_programID(), "Texture1"), 1);
	shader.use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, shape.countofIndices(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
