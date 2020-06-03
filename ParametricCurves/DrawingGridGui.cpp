#include "DrawingGridGui.h"
#include "Axis.h"
// Author : Adam Górski


void DrawingGridGui::setPicture(QPicture pic)
{
	DrawingGridGui::grid_base = pic;
}

QPicture DrawingGridGui::getPicture()
{
	return DrawingGridGui::grid_base;
}

void DrawingGridGui::setGrid()
{
	QPicture current_pic = DrawingGridGui::grid_base;
	QPainter painting_utility(&current_pic);
	for (int i = 0; i < DrawingGridGui::lines_number; i++) {
		int edge_amount = DrawingGridGui::lines_number;
		painting_utility.drawLine(DrawingGridGui::width * i / edge_amount, 0, DrawingGridGui::width * i / edge_amount, DrawingGridGui::height);
		painting_utility.drawLine(0, DrawingGridGui::height * i / edge_amount, DrawingGridGui::width, DrawingGridGui::height * i / edge_amount);
	}
	painting_utility.end();
}