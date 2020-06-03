#include "DrawingAxisGui.h"



void DrawingAxisGui::setPicture(QPicture pic)
{
	DrawingAxisGui::canvas = pic;
}



void DrawingAxisGui::paintDrawingAxisGui()
{
	QPicture drawingCanvas = DrawingAxisGui::canvas;
	QPainter painting_canvas(&drawingCanvas);

	painting_canvas.drawLine(0, DrawingAxisGui::height / 2, DrawingAxisGui::width, DrawingAxisGui::height / 2);
	painting_canvas.drawLine(DrawingAxisGui::width / 2, 0, DrawingAxis::width / 2, DrawingAxis::height);

	painting_canvas.end();
}

QPicture DrawingAxisGui::getPicture()
{
	return DrawingAxisGui::canvas;
}

void DrawingAxisGui::setPointsNumber(int num)
{
	DrawingAxisGui::points_number = num;
}

//void DrawingAxisGui::addToPlot(DrawingPlotGui<double, double> PlotGui)
//{
//
//}