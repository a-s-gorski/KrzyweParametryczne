#pragma once
#include "Axis.h"
#include <stdlib.h> 
class DrawingAxis :
	protected Axis
{
protected:
	int x_min = -100, x_max = 100, y_min = -100, y_max = 100;
	int points_number;
	int** grid_coordinates;
	void defineGrid();

public:
	DrawingAxis(int max_value);
	DrawingAxis(int x, int y);
	DrawingAxis(int x, int y, int num);
	DrawingAxis(int x_minimum, int x_maximum, int y_minimum, int y_maximum);
	DrawingAxis(int x_minimum, int x_maximum, int y_minimum, int y_maximum, int num);
	void setPointsNumber(int num = 100);

};

