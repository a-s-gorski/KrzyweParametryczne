#include "Axis.h"
//
//Axis();	//template 0-100
//Axis(int x);
//Axis(int x, int y);
//Axis(int x, int y, int num);
//Axis(int x1, int x2, int y1, int y2);
//Axis(int x1, int x2, int y1, int y2, int num);


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