#pragma once
#include "Grid.h"
#include <iostream>
class DrawingGrid :
	protected Grid
{
protected:
	int x_min, x_max, y_min, y_max;
	int ID;
	int lines_number;

public:
	DrawingGrid(int grid_id, int x1 = 100, int x2 = -100, int y1 = 100, int y2 = -100, int num = 10);
};

