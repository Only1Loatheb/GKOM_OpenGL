#include "Cylinder.h"



Cylinder::Cylinder(GLfloat r, GLfloat h, GLuint sides)
{

	// changable values 
	this->radius = r;
	this->heightHalf = h/2;
	this->sides = sides;
	// additional helping values
	this->theta =  glm::two_pi<double>() / sides;
	this->halfTheta = theta / 2.0;
	this->minusHeightHalf = -heightHalf;
	this->zeroZeroOne = glm::vec3(.0f, .0f, 1.f);
	this->zeroZeroMinusOne = glm::vec3(.0f, .0f, -1.f);

	addSideVertices();
	addLidsVertices();
	addSideIndices();
	addLidsIndices();
	bindVAO();
}

Cylinder::~Cylinder()
{
}

void Cylinder::addSideVertices()
{
	for (int i = 0; i < sides; i++) {
		glm::vec3 normal = glm::vec3(cos(theta * i), sin(theta * i), 0.0f);
		glm::vec3 position = glm::vec3(glm::vec2(radius * normal), heightHalf);
		saveVertexToVector(position, normal, randomVec2());
	}

	for (int i = 0; i < sides; i++) {
		glm::vec3 normal = glm::vec3(cos(theta * i + halfTheta), sin(theta * i + halfTheta), 0.0f);
		glm::vec3 position = glm::vec3(glm::vec2(radius * normal), minusHeightHalf);
		saveVertexToVector(position, normal, randomVec2());
	}
}

void Cylinder::addLidsVertices()
{
	for (int i = 0; i < sides; i++) {
		glm::vec3 position = glm::vec3(cos(theta * i) * radius, sin(theta * i) * radius, heightHalf);
		saveVertexToVector(position, zeroZeroOne, randomVec2());
	}

	for (int i = 0; i < sides; i++) {
		glm::vec3 position = glm::vec3(
			cos(theta * i + halfTheta) * radius, sin(theta * i + halfTheta) * radius, minusHeightHalf);
		saveVertexToVector(position, zeroZeroMinusOne, randomVec2());
	}
}

void Cylinder::addSideIndices()
{
	for (int i = 0; i < sides; ++i) {
		int i1 = i;
		int i2 = (i1 + 1) % sides;
		int i3 = i1 + sides;
		int i4 = i2 + sides;
		saveIndicesToVector(i1, i3, i2);
		saveIndicesToVector(i4, i2, i3);
	}
}

void Cylinder::addLidsIndices()
{
	int positive = countOfVertices();
	saveVertexToVector(glm::vec3(0.0f, 0.0f, heightHalf), zeroZeroOne, randomVec2());

	int negative = countOfVertices();
	saveVertexToVector(glm::vec3(0.0f, 0.0f, minusHeightHalf), zeroZeroMinusOne, randomVec2());
	// Generate indices lids
	int twoTimesSlices = sides * 2;
	int threeTimesSlices = sides * 3;
	for (int i = twoTimesSlices; i < threeTimesSlices; ++i) {
		int i1 = i;
		int i2 = (i1 + 1) % sides + twoTimesSlices;
		int i3 = i1 + sides;
		int i4 = i2 + sides;
		saveIndicesToVector(i1, positive, i2);
		saveIndicesToVector(i4, i3, negative);
	}
}

float Cylinder::randFloat() const // 0 - 1
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

glm::vec2 Cylinder::randomVec2() const
{
	return glm::vec2(randFloat(), randFloat());
}
