#include "Sphere.h"



Sphere::Sphere(GLfloat r, GLuint stacks, GLuint slices)
{	// changable values
	this->radius = r;
	this->stacks = stacks;
	this->slices = slices;
	// additional helping values
	this->deltaLong = glm::pi<double>() * 2 / slices;
	this->deltaLat = glm::pi<double>() / stacks;
	
	addNorthVertice();
	addMainVertices();
	addSouthVerttice();
	addNorthIndices();
	addMainIndices();
	addSouthIndices();
	bindVAO();
}


Sphere::~Sphere()
{
}

void Sphere::addNorthVertice()
{
	saveVertexToVector(glm::vec3(0.0f, 0.0f, radius), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f));
}

void Sphere::addMainVertices()
{
	for (int i = 1; i < stacks; ++i) {
		for (int j = 0; j <= slices; ++j) {
			glm::vec3 normal = glm::vec3(
				sin(deltaLat * i) * cos(deltaLong * j),
				sin(deltaLat * i) * sin(deltaLong * j),
				cos(deltaLat * i)
			);
			saveVertexToVector(
				normal * radius,
				normal,
				glm::vec2((float)j / slices, 1 - (float)i / stacks));
		}
	}
}

void Sphere::addSouthVerttice()
{
	saveVertexToVector(glm::vec3(0.0f, 0.0f, -radius), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.5f, 0.0f));
}

void Sphere::addNorthIndices()
{
	for (int j = 1; j <= slices; ++j) {
		saveIndicesToVector(0, j, j + 1);
	}
}

void Sphere::addMainIndices()
{
	for (int i = 1; i < stacks; ++i) {
		for (int j = 1; j <= slices; ++j) {
			// each quad gives two triangles
			// triangle one
			saveIndicesToVector(
				(i - 1) * slices + j,
				i * slices + j,
				i * slices + j + 1);
			// triangle two
			saveIndicesToVector(
				(i - 1) * slices + j,
				i * slices + j + 1,
				(i - 1) * slices + j + 1);
		}
	}
}

void Sphere::addSouthIndices()
{
	int numVertices = (slices + 1) * (stacks - 1) + 2;
	int temp = numVertices - 1;
	for (int j = temp - slices; j < temp; ++j) {
		saveIndicesToVector(temp, j, j - 1);
	}
}
