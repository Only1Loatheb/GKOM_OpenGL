#include "Sphere.h"



Sphere::Sphere()
{	// changable values
	this->radius = 1.0f;
	this->stacks = 20; 
	this->slices = 20;
	// additional helping values
	this->deltaLong = glm::pi<double>() * 2 / slices;
	this->deltaLat = glm::pi<double>() / stacks;
	//loops
	// North pole point
	saveVertexToVector(glm::vec3(0.0f, 0.0f, radius), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f));
	// vertices on the main body
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
	// South pole point
	saveVertexToVector(glm::vec3(0.0f, 0.0f, -radius), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.5f, 0.0f));
	//add indices in North Pole region (no. of elements is slices * 3)
	for (int j = 1; j <= slices; ++j) {
		saveIndicesToVector(0, j, j + 1);
	}
	// add body (no. of element is (stacks - 2) * slices * 6
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
	//add indices in South Pole Region (no. of element is slices * 3)
	int numVertices = (slices + 1) * (stacks - 1) + 2;
	int temp = numVertices - 1;
	for (int j = temp - slices; j < temp; ++j) {
		saveIndicesToVector(temp, j, j - 1);
	}

	bindVAO();
}


Sphere::~Sphere()
{
}
