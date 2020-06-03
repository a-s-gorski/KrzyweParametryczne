#pragma once
// Author : Adam Górski

#include "DrawingAxis.h"
#include <Utility>
#include <QtWidgets>
#include <vector>
#include "DrawingGridGui.h"

class DrawingAxisGui :
	public DrawingAxis
{
protected:
	QPicture canvas;
	int** grid_coordinates;
	friend class DrawingGridGui;
public:
	void setPicture(QPicture pic);
	QPicture getPicture();
	void paintDrawingAxisGui();
	void setPointsNumber(int num = 100);
	//void addToPlot(DrawingPlotGui<double, double> PlotGui); // change to Grid
};

