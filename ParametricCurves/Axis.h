#pragma once
class Axis
{
protected:
	int height = 480;
	int width = 640;

public:
	~Axis();
	void setScreenParameters(int parameter);
	void setScreenParameters(int h, int w);
	int getScreenHeight();
	int getScreenWidth();

};

