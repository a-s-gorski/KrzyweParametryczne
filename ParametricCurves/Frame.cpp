#include "Frame.h"

Frame::Frame() {}
Frame::~Frame(){}


void Frame::setParam(double h, double w) 
{
	Frame::screen_height = h;
	Frame::screen_width = w;
}

