#include "Box.h"


Box::Box(GLfloat side)
{
	this->halfSide = side / 2.0f;
	verticesCount = 8 * 6 * 4;
	indicesCount = 12 * 3;
	
	addVertices();
	calcNormalVec(getVertices());
	addIndices();
	bindVAO();
}


Box::~Box()
{
}

void Box::addVertices()
{
	GLfloat _0_33 = 1.0f / 3.0f;
	GLfloat _0_66 = 2.0f / 3.0f;
	GLfloat _O_5 = 0.5f;
	setVertices(vector<GLfloat>{
		// coordinates			// normal			// texture
		//up
		-halfSide, halfSide, halfSide, 0.0f, 0.0f, 0.0f, _O_5, _0_33,
			halfSide, halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 0.25f, 0.0f,
			halfSide, halfSide, halfSide, 0.0f, 0.0f, 0.0f, 0.25f, _0_33,
			-halfSide, halfSide, -halfSide, 0.0f, 0.0f, 0.0f, _O_5, 0.0f,
			//down
			-halfSide, -halfSide, halfSide, 0.0f, 0.0f, 0.0f, _O_5, _0_66,
			halfSide, -halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 0.25f, 1.0f,
			-halfSide, -halfSide, -halfSide, 0.0f, 0.0f, 0.0f, _O_5, 1.0f,
			halfSide, -halfSide, halfSide, 0.0f, 0.0f, 0.0f, 0.25f, _0_66,
			//right
			-halfSide, halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 0.75f, _0_33,
			halfSide, -halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 1.0f, _0_66,
			halfSide, halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 1.0f, _0_33,
			-halfSide, -halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 0.75f, _0_66,
			//left
			-halfSide, halfSide, halfSide, 0.0f, 0.0f, 0.0f, _O_5, _0_33,
			halfSide, -halfSide, halfSide, 0.0f, 0.0f, 0.0f, 0.25f, _0_66,
			-halfSide, -halfSide, halfSide, 0.0f, 0.0f, 0.0f, _O_5, _0_66,
			halfSide, halfSide, halfSide, 0.0f, 0.0f, 0.0f, 0.25f, _0_33,
			//back
			-halfSide, -halfSide, halfSide, 0.0f, 0.0f, 0.0f, _O_5, _0_66,
			-halfSide, halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 0.75f, _0_33,
			-halfSide, halfSide, halfSide, 0.0f, 0.0f, 0.0f, _O_5, _0_33,
			-halfSide, -halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 0.75f, _0_66,
			//front
			halfSide, -halfSide, halfSide, 0.0f, 0.0f, 0.0f, 0.25f, _0_66,
			halfSide, halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 0.0f, _0_33,
			halfSide, -halfSide, -halfSide, 0.0f, 0.0f, 0.0f, 0.0f, _0_66,
			halfSide, halfSide, halfSide, 0.0f, 0.0f, 0.0f, 0.25f, _0_33,
	});
}

void Box::addIndices()
{
	for (int i = 0; i < indicesCount; i += 4)
	{
		saveIndicesToVector(i,i+1,i+2);
		saveIndicesToVector(i+1, i, i + 3);
	}
}

void Box::calcNormalVec(vector<GLfloat>& v)
{
	auto vAC = getVertexAtributesCount();
	auto vAC2 = 2 * vAC;
	auto vAC3 = 3 * vAC;
	auto vAC4 = 4 * vAC;
	auto sizeOf3Floats = sizeof(GLfloat) * 3;
	for (int i = 0; i < getVertices().size(); i += vAC4)
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
		// ib4 jest niewydajnie wiêc u¿yjmy c
		memcpy(&v[i + 3], &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC], &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC2], &normal.x, sizeOf3Floats);
		memcpy(&v[i + 3 + vAC3], &normal.x, sizeOf3Floats);
		
	}
}