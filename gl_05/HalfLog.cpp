#include "HalfLog.h"



HalfLog::HalfLog(GLfloat r, GLfloat h, GLuint slices, GLfloat part)
	:	
	// changable values 
	radius(r),
	heightHalf(h / 2.0f),
	part(part),
	// additional helping values
	sides(slices * part + 1),
	theta(glm::two_pi<double>() / slices),
	minusHeightHalf(-heightHalf),
	zeroZeroOne(glm::vec3(.0f, .0f, 1.f)),
	zeroZeroMinusOne(glm::vec3(.0f, .0f, -1.f))
{
	addSideVertices();
	addLidsVertices();
	addSideIndices();
	addLidsIndices();
	addCutVertInd();
	bindVAO();
}

HalfLog::~HalfLog()
{
}

void HalfLog::addSideVertices()
{
	for (int i = 0; i < sides; i++) {
		glm::vec3 normal(cos(theta * i), sin(theta * i), 0.0f);
		glm::vec3 position(glm::vec2(radius * normal), heightHalf);
		saveVertexToVector(position, normal, randomVec2());
	}

	for (int i = 0; i < sides; i++) {
		glm::vec3 normal(cos(theta * i), sin(theta * i), 0.0f);
		glm::vec3 position(glm::vec2(radius * normal), minusHeightHalf);
		saveVertexToVector(position, normal, randomVec2());
	}
}

void HalfLog::addLidsVertices()
{
	for (int i = 0; i < sides; i++) {
		glm::vec3 position(cos(theta * i) * radius, sin(theta * i) * radius, heightHalf);
		saveVertexToVector(position, zeroZeroOne, randomVec2());
	}

	for (int i = 0; i < sides; i++) {
		glm::vec3 position(cos(theta * i) * radius, sin(theta * i) * radius, minusHeightHalf);
		saveVertexToVector(position, zeroZeroMinusOne, randomVec2());
	}
}

void HalfLog::addSideIndices()
{
	int sidesMinusOne = sides - 1;
	for (int i = 0; i < sidesMinusOne; ++i) {
		int i1 = i;
		int i2 = i1 + 1;
		int i3 = i1 + sides;
		int i4 = i2 + sides;
		saveIndicesToVector(i1, i3, i2);
		saveIndicesToVector(i4, i2, i3);
	}
}

void HalfLog::addLidsIndices()
{
	//poles
	int positivePoleIndex = countOfVertices();
	saveVertexToVector(glm::vec3(0.0f, 0.0f, heightHalf), zeroZeroOne, randomVec2());
	int negativePoleIndex = countOfVertices();
	saveVertexToVector(glm::vec3(0.0f, 0.0f, minusHeightHalf), zeroZeroMinusOne, randomVec2());
	// Generate indices lids
	int twoTimesSlices = sides * 2;
	int threeTimesSlices = sides * 3 - 1;
	for (int i = twoTimesSlices; i < threeTimesSlices; ++i) {
		int i1 = i;
		int i2 = i1 + 1;
		int i3 = i1 + sides;
		int i4 = i2 + sides;
		saveIndicesToVector(i1, positivePoleIndex, i2);
		saveIndicesToVector(i4, i3, negativePoleIndex);
	}
}

void HalfLog::addCutVertInd()
{
	glm::vec3 positivePolePosition(0.0f, 0.0f, heightHalf);
	//poles
	glm::vec3 firstPositivePosition(cos(0) * radius, sin(0) * radius, heightHalf);
	glm::vec3 firstNegativePosition(cos(0) * radius, sin(0) * radius, minusHeightHalf);
	
	glm::vec3 firstNormal = calcNormalVec(positivePolePosition,firstNegativePosition, firstPositivePosition);

	int firstPositiveCutIndex = countOfVertices();
	saveVertexToVector(firstPositivePosition, firstNormal, randomVec2());
	int firstNegativeCutIndex = countOfVertices();
	saveVertexToVector(firstNegativePosition, firstNormal, randomVec2());
	int firstPositivePoleIndex = countOfVertices();
	saveVertexToVector(positivePolePosition, firstNormal, randomVec2());
	int firstNegativePoleIndex = countOfVertices();
	saveVertexToVector(-positivePolePosition, firstNormal, randomVec2());


	GLfloat thetaTimesSidesMinusOne = theta * (sides-1);
	glm::vec3 secondPositivePosition(cos(thetaTimesSidesMinusOne) * radius, sin(thetaTimesSidesMinusOne) * radius, heightHalf);
	glm::vec3 secondNegativePosition(cos(thetaTimesSidesMinusOne) * radius, sin(thetaTimesSidesMinusOne) * radius, minusHeightHalf);
	
	glm::vec3 secondNormal = calcNormalVec(positivePolePosition,secondPositivePosition, secondNegativePosition);

	int secondPositiveCutIndex = countOfVertices();
	saveVertexToVector(secondPositivePosition, secondNormal, randomVec2());
	int secondNegativeCutIndex = countOfVertices();
	saveVertexToVector(secondNegativePosition, secondNormal, randomVec2());
	int secondPositivePoleIndex = countOfVertices();
	saveVertexToVector(positivePolePosition, secondNormal, randomVec2());
	int secondNegativePoleIndex = countOfVertices();
	saveVertexToVector(-positivePolePosition, secondNormal, randomVec2());

	saveIndicesToVector(firstPositiveCutIndex, firstNegativeCutIndex, firstPositivePoleIndex);
	saveIndicesToVector(firstNegativeCutIndex, firstNegativePoleIndex, firstPositivePoleIndex);
	saveIndicesToVector(secondPositiveCutIndex, secondNegativeCutIndex, secondPositivePoleIndex);
	saveIndicesToVector(secondNegativeCutIndex, secondNegativePoleIndex, secondPositivePoleIndex);

}


float HalfLog::randFloat() const// 0 - 1
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

glm::vec2 HalfLog::randomVec2()const
{
	return glm::vec2(randFloat(), randFloat());
}
