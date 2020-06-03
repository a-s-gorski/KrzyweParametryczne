#include "Axis.h"
// Author : Adam Górski

Axis::~Axis()
{
}

void Axis::setScreenParameters(int parameter) 
{
	Axis::height = parameter;
	Axis::width = parameter;
}

void Axis::setScreenParameters(int h, int w)
{
	Axis::height = h;
	Axis::width = w;
}

int Axis::getScreenHeight()
{
	return Axis::height;
}

int Axis::getScreenWidth()
{
	return Axis::width;
}