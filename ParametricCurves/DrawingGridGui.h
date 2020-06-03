#pragma once
#include "DrawingGrid.h"
#include "DrawingAxisGui.h"
#include <QtWidgets>

class DrawingGridGui :
	public DrawingGrid
{
public:
	DrawingGridGui(DrawingAxisGui createAxis);
	void drawOnAxis();

private:
	QPicture grid_base;
	
};

