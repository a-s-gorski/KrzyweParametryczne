#pragma once

class Frame
{
public:
	Frame();
	~Frame();
protected:
	double screen_height = 480.0;
	double screen_width = 640.0;
	void setParam(double h, double w);
	double getHeight();
	double getWidth();

};

