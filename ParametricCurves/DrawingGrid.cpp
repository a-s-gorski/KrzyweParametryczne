#include "DrawingGrid.h"

DrawingGrid::DrawingGrid(int grid_id, int x1, int x2, int y1, int y2, int num)
{
	DrawingGrid::ID = grid_id;
	DrawingGrid::x_max = x1;
	DrawingGrid::x_min = x2;
	DrawingGrid::y_max = y1;
	DrawingGrid::y_min = y2;
	DrawingGrid::lines_number = num;

}
