#include "HalfLog.h"



HalfLog::HalfLog()
{
	// changable values 
	this->radius = 0.5f;
	this->height = 1.5f;
	this->slices = 20;
	// additional helping values
	this->theta  = glm::pi<double>() * 2 / slices;
	this->halfTheta = theta / 2.0;
	this->minusHeight = -height;
	this->zeroZeroOne = glm::vec3(.0f, .0f, 1.f);
	this->zeroZeroMinusOne = glm::vec3(.0f, .0f, -1.f);
	//loops
	// vertices side
	for (int i = 0; i < slices; i++) {
		glm::vec3 normal = glm::vec3(cos(theta * i), sin(theta * i), 0.0f);
		glm::vec3 position = glm::vec3(glm::vec2(radius * normal), height);
		saveVertexToVector(position, normal,randomVec2());
	}

	for (int i = 0; i < slices; i++) {
		glm::vec3 normal = glm::vec3(cos(theta * i + halfTheta), sin(theta * i + halfTheta), 0.0f);
		glm::vec3 position = glm::vec3(glm::vec2(radius * normal), minusHeight);
		saveVertexToVector(position, normal, randomVec2());
	}
	// vertices lids
	for (int i = 0; i < slices; i++) {
		glm::vec3 position = glm::vec3(cos(theta * i) * radius , sin(theta * i) * radius, height);
		saveVertexToVector(position, zeroZeroOne, randomVec2());
	}

	for (int i = 0; i < slices; i++) {
		glm::vec3 position = glm::vec3(
			cos(theta * i + halfTheta) * radius, sin(theta * i + halfTheta) * radius, minusHeight);
		saveVertexToVector(position, zeroZeroMinusOne, randomVec2());
	}
	
	// Generate indices for triangular mesh 
	for (int i = 0; i < slices; ++i) {
		int i1 = i;
		int i2 = (i1 + 1) % slices;
		int i3 = i1 + slices;
		int i4 = i2 + slices;
		saveIndicesToVector(i1, i3, i2);
		saveIndicesToVector(i4, i2, i3);
	}

	//poles
	int positive = countOfVertices();
	saveVertexToVector(glm::vec3(0.0f, 0.0f, height), zeroZeroOne, randomVec2());

	int negative = countOfVertices();
	saveVertexToVector(glm::vec3(0.0f, 0.0f, minusHeight), zeroZeroMinusOne, randomVec2());
	int twoTimesSlices = slices * 2;
	for (int i = twoTimesSlices; i < slices * 3 ; ++i) {
		int i1 = i;
		int i2 = (i1 + 1) % slices + twoTimesSlices;
		int i3 = i1 + slices;
		int i4 = i2 + slices;
		saveIndicesToVector(i1, positive, i2);
		saveIndicesToVector(i4, i3, negative);
	}
	bindVAO();
}

HalfLog::~HalfLog()
{
}

float randFloat() // 0 - 1
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

glm::vec2 randomVec2()
{
	return glm::vec2(randFloat(), randFloat());
}
