#pragma once
#include <QtWidgets>
#include "DrawingPlot.h"



template <class X, class Y>
class DrawingPlotGui :
	public DrawingPlot<X,Y>
{
public:
	void setPicture(QPicture picture_base);
	void drawPlot();
protected:
	QPicture drawingPanel;
};

