#include "Box.h"


Box::Box()
{
	GLfloat _0_33 = 1.0f / 3.0f;
	GLfloat _0_66 =  2.0f / 3.0f;
	vertexAtributesCount = 8;
	verticesCount = 24 * vertexAtributesCount;
	indicesCount = 12 * 3;
	vertices = vector<GLfloat>{
		// coordinates			// normal			// texture
		//up
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.5f,  _0_33,
		0.5f,  0.5f, -0.5f,	    0.0f, 0.0f, 0.0f,	0.25f,  0.0f,
		0.5f,  0.5f,  0.5f,  	0.0f, 0.0f, 0.0f,	0.25f,  _0_33,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.5f,  0.0f,
		//down
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.5f, _0_66,
		0.5f, -0.5f, -0.5f,	    0.0f, 0.0f, 0.0f,	0.25f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.5f, 1.0f,
		0.5f, -0.5f,  0.5f,	    0.0f, 0.0f, 0.0f,	0.25f, _0_66,
		//right
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.75f, _0_33,
		0.5f, -0.5f, -0.5f,  	0.0f, 0.0f, 0.0f,	1.0f, _0_66,
		0.5f,  0.5f, -0.5f, 	0.0f, 0.0f, 0.0f,	1.0f, _0_33,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.75f, _0_66,
		//left
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.5f, _0_33,
		0.5f, -0.5f,  0.5f, 	0.0f, 0.0f, 0.0f,	0.25f, _0_66,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.5f, _0_66,
		0.5f,  0.5f,  0.5f, 	0.0f, 0.0f, 0.0f,	0.25f, _0_33,
		//back
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.5f,  _0_66,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.75f, _0_33,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.5f, _0_33,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.75f,  _0_66,
		//front
		0.5f, -0.5f,  0.5f, 	0.0f, 0.0f, 0.0f,	0.25f, _0_66,
		0.5f,  0.5f, -0.5f,	    0.0f, 0.0f, 0.0f,	0.0f, _0_33,
		0.5f, -0.5f, -0.5f, 	0.0f, 0.0f, 0.0f,	0.0f, _0_66,
		0.5f,  0.5f,  0.5f, 	0.0f, 0.0f, 0.0f,	0.25f, _0_33,
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
	for (int i = 0; i < indicesCount; i += 4)
	{
		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 2);
		indices.push_back(i + 1);
		indices.push_back(i);
		indices.push_back(i + 3);
	}
	bindVAO();
}


Box::~Box()
{
}

void Box::calcNormalVec(vector<GLfloat>& v)
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
		// ib4 jest niewydajnie wi�c u�ylmy c
		memcpy(&v[i + 3], &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC], &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC2], &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC3], &normal.x, sizeOf3Floats);
		
	}
}