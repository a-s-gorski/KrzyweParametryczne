#pragma once
#include "DrawingAxis.h"
#include <Utility>
#include <QtWidgets>
#include <vector>

class DrawingAxisGui :
	public DrawingAxis
{
private:
	QPicture canvas;
	QPainter painter;
	int** grid_coordinates;
public:
	void setPicture(QPicture pic);
	void setPainter(QPainter paint);
	void paintDrawingAxisGui();

};

