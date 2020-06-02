#include "DrawingAxisGui.h"

void DrawingAxisGui::setPicture(QPicture pic)
{
	DrawingAxisGui::canvas = pic;
}

void DrawingAxisGui::setPainter(QPainter paint)
{
	DrawingAxisGui::painter = paint;
}

void DrawingAxisGui::paintDrawingAxisGui()
{
	QPicture drawingCanvas = DrawingAxisGui::canvas;
	QPainter painting_canvas(&drawingCanvas);

	painting_canvas.drawLine(0, DrawingAxisGui::height / 2, DrawingAxisGui::width, DrawingAxisGui::height / 2);
	painting_canvas.drawLine(DrawingAxisGui::width / 2, 0, DrawingAxis::width / 2, DrawingAxis::height);

	painting_canvas.end();
}