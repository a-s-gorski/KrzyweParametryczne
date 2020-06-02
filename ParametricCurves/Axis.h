#pragma once
class Axis
{
protected:
	int height = 480;
	int width = 640;

public:
	Axis();	//template 0-100_
	void setScreenParameters(int parameter);
	void setScreenParameters(int h, int w);
	int getScreenHeight();
	int getScreenWidth();

};

