#include "Figure.h"	
 

Shape::Shape()
:vertexAtributesCount(8),
verticesCount(24 * vertexAtributesCount),
indicesCount(12 * 3)
{
	vertices = vector<GLfloat>{
		// coordinates			// normal			// texture
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
	
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,
		
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,

		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f,  1.0f,	
	};

	calcNormalVec(vertices);
#pragma region showNormals 
	auto vAC4 = 4 * vertexAtributesCount;;
	for (int i = 0; i < verticesCount; i += vAC4)
	{
	cout << vertices[i + 3] << " " << vertices[i + 4] << " " << vertices[i + 5] << endl;
	}
#pragma endregion
	indices = vector<GLuint>();
	for (int i = 0; i < indicesCount; i+=4)
	{
		indices.push_back(i);
		indices.push_back(i+1);
		indices.push_back(i+2);
		indices.push_back(i+1);
		indices.push_back(i);
		indices.push_back(i+3);
	}

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeofVertices(), getVertices(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeofIndices(), getIndices(), GL_STATIC_DRAW);

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


Shape::~Shape()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

GLfloat* Shape::getVertices() const
{
	return (GLfloat*)&vertices[0];
}
GLuint* Shape::getIndices() const
{
	return (GLuint*)&indices[0];
}

GLsizeiptr Shape::sizeofVertices() const
{
	return sizeof(GLfloat) * verticesCount;
}

GLsizeiptr Shape::sizeofIndices() const
{
	return sizeof(GLuint) * indicesCount;
}

GLsizei Shape::countofIndices() const
{
	return indicesCount;
}

void Shape::draw() const
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, countofIndices(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Shape::calcNormalVec(vector<GLfloat>& v)
{
	auto vAC = vertexAtributesCount;
	auto vAC2 = 2 * vAC;
	auto vAC3 = 3 * vAC;
	auto vAC4 = 4 * vAC;
	auto sizeOf3Floats = sizeof(GLfloat) * 3;
	for (int i = 0; i < verticesCount; i += vAC4)
	{
		glm::vec3 p1 = glm::make_vec3(&v[i]);
		glm::vec3 p2 = glm::make_vec3(&v[i + vAC]);
		glm::vec3 p3 = glm::make_vec3(&v[i + vAC2]);

		glm::vec3 l = p2 - p1;
		glm::vec3 k = p3 - p1;

		glm::vec3 normal = glm::cross(k, l);
		/*
		v[i + 3] = v[i + 3 + vAC] = v[i + 3 + vAC2] = v[i + 3 + vAC3] = normal.x;
		v[i + 4] = v[i + 4 + vAC] = v[i + 4 + vAC2] = v[i + 4 + vAC3] = normal.y;
		v[i + 5] = v[i + 5 + vAC] = v[i + 5 + vAC2] = v[i + 5 + vAC3] = normal.z;
		*/
		// ib4 jest niewydajnie wiêc u¿ylmy c
		memcpy(&v[i + 3],		 &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC ], &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC2], &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC3], &normal.x, sizeOf3Floats);
		
	}

}