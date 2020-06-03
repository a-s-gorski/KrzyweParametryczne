#include "DrawingAxis.h"
#include <stdlib.h> 

DrawingAxis::DrawingAxis()
{

}


DrawingAxis::DrawingAxis(int max_value)
{
	DrawingAxis::x_min = max_value - 2 * (abs(max_value));
	DrawingAxis::y_min = max_value - 2 * (abs(max_value));
	DrawingAxis::x_max = max_value;
	DrawingAxis::y_max = max_value;
}

DrawingAxis::DrawingAxis(int x, int y)
{
	DrawingAxis::x_max = x;
	DrawingAxis::y_max = y;
	DrawingAxis::x_min = x - 2 * (abs(x));
	DrawingAxis::y_min = y - 2 * (abs(y));
}

DrawingAxis::DrawingAxis(int x, int y, int num)
{
	DrawingAxis::x_max = x;
	DrawingAxis::y_max = y;
	DrawingAxis::x_min = x - 2 * (abs(x));
	DrawingAxis::y_min = y - 2 * (abs(y));
	DrawingAxis::points_number = num;
}

DrawingAxis::DrawingAxis(int x_minimum, int x_maximum, int y_minimum, int y_maximum)
{
	DrawingAxis::x_max = x_maximum;
	DrawingAxis::x_min = x_minimum;
	DrawingAxis::y_max = y_maximum;
	DrawingAxis::y_min = y_minimum;
}

DrawingAxis::DrawingAxis(int x_minimum, int x_maximum, int y_minimum, int y_maximum, int num)
{
	DrawingAxis::x_max = x_maximum;
	DrawingAxis::x_min = x_minimum;
	DrawingAxis::y_max = y_maximum;
	DrawingAxis::y_min = y_minimum;
	DrawingAxis::points_number = num;
}



DrawingAxis::DrawingAxis(const DrawingAxis &copiedAxis)
{
	DrawingAxis::x_max = copiedAxis.x_max;
	DrawingAxis::x_min = copiedAxis.x_min;
	DrawingAxis::y_max = copiedAxis.y_max;
	DrawingAxis::y_min = copiedAxis.y_min;
	DrawingAxis::points_number = copiedAxis.points_number;
}


void DrawingAxis::setPointsNumber(int num)
{
	if (num > 1) {
		DrawingAxis::points_number = num;
	}
}

