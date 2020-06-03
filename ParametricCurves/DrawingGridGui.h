#pragma once
#include "DrawingAxisGui.h"
#include "DrawingGrid.h"
#include "DrawingAxis.h"
#include <QtWidgets>
#include "Axis.h"
// Author : Adam Górski



class DrawingGridGui : public DrawingGrid
{
private:
	QPicture grid_base;
public:
	void setPicture(QPicture pic);
	QPicture getPicture();
	void drawGrid();
	void setGrid();
};

