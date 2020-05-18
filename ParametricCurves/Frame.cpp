#include "Frame.h"

//	Author : Adam Górski 


Frame::Frame() {}

Frame::~Frame(){}


void Frame::setParam(double h, double w) 
{
	Frame::screen_height = h;
	Frame::screen_width = w;
}

double Frame::getHeight() {
	return Frame::screen_height;
}

double Frame::getWidth() {
	return Frame::screen_width;
}