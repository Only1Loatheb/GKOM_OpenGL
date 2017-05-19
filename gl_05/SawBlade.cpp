#include "SawBlade.h"

SawBlade::SawBlade()
{
	// changable values 
	this->fullLength = 4.0f;
	this->numberOfteeth = 5;
	this->toothWidth = 0.2f;
	this->toothHeight = 0.4f;
	this->toothSet = 0.1f;
	this->baseHeight = 0.0f;
	// additional helping values
	this->verricesInTooth = 10;
	this->toothLength = fullLength / numberOfteeth;
	this->halfToothLength = toothLength / 2.0f;
	this->halfToothWidth = toothWidth / 2.0f;
	this->minusHalfToothWidth = -halfToothWidth;
	// volatile values
	this->halfLength = fullLength / 2.0f;
	this->inverted = false;
	currentVecIndex = 0;
	//loops
	glm::vec3 p1 = makePoint1();
	glm::vec3 p2 = makePoint2();
	glm::vec3 p3 = makePoint3();
	glm::vec3 norm = calcNormalVec(p1, p3, p2);
	saveVertexToVector(p1, norm, glm::vec2(0.5f, 0.0f));
	saveVertexToVector(p2, norm, glm::vec2(0.5f, 0.25f));
	for (int i = 0; i < numberOfteeth; ++i)
	{	
		addTriangle1();
		addTriangle2();
		addTriangle3();
		addTriangle4();
		addTriangle5();
		currentVecIndex += verricesInTooth;
		halfLength -= toothLength;
		inverted = !inverted;
	}
	bindVAO();
}


SawBlade::~SawBlade()
{
}

void SawBlade::addTriangle1()
{
	glm::vec3 p1 = makePoint1();
	glm::vec3 p2 = makePoint2();
	glm::vec3 p3 = makePoint3();
	glm::vec3 norm = calcNormalVec(p1, p3, p2);
	if (inverted)
	{
		norm = calcNormalVec(p1, p2, p3);
	}
	saveVertexToVector(p3, norm, glm::vec2(0.0f, 0.0f));
	saveIndicesToVector(currentVecIndex, currentVecIndex + 1, currentVecIndex + 2);
}

void SawBlade::addTriangle2()
{
	glm::vec3 p1 = makePoint1();
	glm::vec3 p2 = makePoint2();
	glm::vec3 p3 = makePoint3();
	glm::vec3 p4 = makePoint4();
	glm::vec3 p5 = makePoint5();

	glm::vec3 normEdge = calcNormalVec(p2, p3, p4);
	glm::vec3 normMid = calcNormalVec(p1, p5, p4);
	if (inverted)
	{
		normEdge = calcNormalVec(p2, p4, p3 );
		normMid = calcNormalVec(p1, p4, p5);
	}
	saveVertexToVector(p2, normEdge, glm::vec2(0.0f, 0.25f));
	saveVertexToVector(p3, normMid, glm::vec2(0.0f, 1.0f));
	saveVertexToVector(p4, normMid, glm::vec2(0.5f, 1.0f));
	saveIndicesToVector(currentVecIndex+3, currentVecIndex + 4, currentVecIndex + 5);
	
}

void SawBlade::addTriangle3()
{
	glm::vec3 p3 = makePoint3();
	glm::vec3 p4 = makePoint4();
	glm::vec3 p5 = makePoint5();
	glm::vec3 p6 = makePoint6();

	glm::vec3 normEdge = calcNormalVec(p3, p6, p4);
	if (inverted)
	{
		normEdge = calcNormalVec(p3, p4, p6);
	}
	saveVertexToVector(p6, normEdge, glm::vec2(0.5f, 0.25f));
	saveIndicesToVector(currentVecIndex + 4, currentVecIndex + 5, currentVecIndex + 6);
}

void SawBlade::addTriangle4()
{
	glm::vec3 p2 = makePoint2();
	glm::vec3 p4 = makePoint4();
	glm::vec3 p6 = makePoint6();

	glm::vec3 norm = calcNormalVec(p2, p4, p6);
	if (inverted)
	{
		norm = calcNormalVec(p2, p6, p4);
	}
	saveVertexToVector(p2, norm, glm::vec2(0.5f, 0.25f));
	saveVertexToVector(p4, norm, glm::vec2(0.75f, 1.0f));
	saveVertexToVector(p6, norm, glm::vec2(1.0f, 0.25f));
	saveIndicesToVector(currentVecIndex + 7, currentVecIndex + 8, currentVecIndex + 9);
}

void SawBlade::addTriangle5()
{
	glm::vec3 p3 = makePoint3();
	glm::vec3 p5 = makePoint5();
	glm::vec3 p6 = makePoint6();
	glm::vec3 norm = calcNormalVec(p3, p5, p6);
	if (inverted)
	{
		norm = calcNormalVec(p3, p6, p5);
	}
	saveVertexToVector(p5, norm, glm::vec2(0.5f, 0.0f));
	saveVertexToVector(p6, norm, glm::vec2(0.5f, 0.25f));
	saveIndicesToVector(currentVecIndex + 2, currentVecIndex + 10, currentVecIndex + 11);
}


glm::vec3 SawBlade::makePoint1()
{
	return glm::vec3(halfLength,baseHeight,inverted ? minusHalfToothWidth : halfToothWidth);
}

glm::vec3 SawBlade::makePoint2()
{
	return glm::vec3(halfLength, baseHeight, inverted ? halfToothWidth : minusHalfToothWidth);
}

glm::vec3 SawBlade::makePoint3()
{
	return glm::vec3(halfLength - halfToothLength, baseHeight, inverted ? minusHalfToothWidth : halfToothWidth);
}

glm::vec3 SawBlade::makePoint4()
{
	return glm::vec3(halfLength - halfToothLength, baseHeight - toothHeight , inverted ? (halfToothWidth +toothSet) : (minusHalfToothWidth - toothSet));
}

glm::vec3 SawBlade::makePoint5()
{
	return glm::vec3(halfLength - toothLength, baseHeight, inverted ? minusHalfToothWidth : halfToothWidth);
}

glm::vec3 SawBlade::makePoint6()
{
	return glm::vec3(halfLength- toothLength, baseHeight, inverted ? halfToothWidth : minusHalfToothWidth);
}

