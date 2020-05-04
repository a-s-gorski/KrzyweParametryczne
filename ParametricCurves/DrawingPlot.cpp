// Autor :  Adam Górski

#include "DrawingPlot.h"
#include <QtWidgets/QApplication>
#include <QtWidgets>
#include <iostream>
#include <vector>
#include <utility>
#include "Frame.h"

using namespace std;


template <class X, class Y>
void DrawingPlot<X, Y>::setPicture(QPicture picture_base) {
	DrawingPlot::drawingPanel = picture_base;
}

template<class X, class Y>
void DrawingPlot<X, Y>::drawPlot() {
	QPicture drawingCanvas = DrawingPlot::drawingPanel;
	QPainter painting_canvas(&drawingCanvas);
	painting_canvas.setRenderHint(QPainter::Antialiasing);
	for (int i = 1; i < DrawingPlot::points.size(); i++) {
		X x1 = DrawingPlot::coordinates[i - 1][0];
		Y y1 = DrawingPlot::coordinates[i - 1][1];
		X x2 = DrawingPlot::coordinates[i][0];
		Y y2 = DrawingPlot::coordinates[i][1];

		painting_canvas.drawLine(x1, y1, x2, y2);
	}
	painting_canvas.end();
#ifdef _DEBUG
	cout << "DrawingPlot : drawing plot lines conecting coordinates \n";
#endif // _DEBUG

	for (int i = 0; i < DrawingPlot::points.size(); i++) {
		delete[] DrawingPlot::coordinates[i];
	}
	delete[] DrawingPlot::coordinates;
#ifdef _DEBUG
	cout << "DrawingPlot: destructor\n";
	cout << "DrawingPlot: deleting dynamic 2d array coordinates\n";
#endif // _DEBUG

}
template <class X, class Y>
void DrawingPlot<X, Y>::get_edge_values() {
#ifdef _DEBUG
	cout << "DrawingPlot : getting maximum and minimum values from points - x-axis and y-axis \n";
#endif // _DEBUG
	DrawingPlot::x_axis_max = DrawingPlot::points[0].first;
	DrawingPlot::x_axis_min = DrawingPlot::points[0].first;
	DrawingPlot::y_axis_max = DrawingPlot::points[0].second;
	DrawingPlot::y_axis_min = DrawingPlot::points[0].second;

	for (int i = 1; i < DrawingPlot::points.size(); i++) {
		pair <X, Y> current_coord = DrawingPlot::points[i];
		DrawingPlot::x_axis_max = max(current_coord.first, DrawingPlot::x_axis_max);
		DrawingPlot::x_axis_min = min(current_coord.first, DrawingPlot::x_axis_min);
		DrawingPlot::y_axis_max = max(current_coord.second, DrawingPlot::y_axis_max);
		DrawingPlot::y_axis_min = min(current_coord.second, DrawingPlot::y_axis_min);
	}

}
template <class X, class Y>
void DrawingPlot<X, Y>::rescale_drawing() {
#ifdef _DEBUG
	cout << "DrawingPlot : moving to window, then interpolation and rescaling\n";
#endif // _DEBUG
	X X_length = DrawingPlot::x_axis_max - DrawingPlot::x_axis_min;
	Y Y_length = DrawingPlot::y_axis_max - DrawingPlot::y_axis_min;

	if ((Y_length / X_length) >= ((Y)DrawingPlot::screen_height / (X)DrawingPlot::screen_width)) {
		DrawingPlot::X_length_new = (X)DrawingPlot::screen_width;
		DrawingPlot::Y_length_new = Y_length * ((X)screen_width / X_length);
	}
	else {
		DrawingPlot::X_length_new = X_length * ((Y)DrawingPlot::screen_height / Y_length);
		DrawingPlot::Y_length_new = (Y)DrawingPlot::screen_height;
	}

	for (int i = 0; i < DrawingPlot::points.size(); i++) {
		DrawingPlot::coordinates[i][0] = DrawingPlot::X_length_new / X_length * (DrawingPlot::points[i].first - DrawingPlot::x_axis_min);
		DrawingPlot::coordinates[i][1] = (-1.0) * DrawingPlot::Y_length_new / Y_length * (DrawingPlot::points[i].second - DrawingPlot::y_axis_min - (Y)screen_height);
	}

}

template <class X, class Y>
void DrawingPlot<X, Y>::setPlot(vector <pair<X, Y>> values) {
	DrawingPlot::points = values;
	DrawingPlot::coordinates = new X * [DrawingPlot::points.size()];
	for (int i = 0; i < DrawingPlot::points.size(); i++) {
		DrawingPlot::coordinates[i] = new Y[2];
#ifdef _DEBUG
		cout << "DrawingPlot : creating dynamicly allocated array(2d) by assigning pointes of pointers\n";
#endif // _DEBUG
	}
	DrawingPlot::get_edge_values();
	DrawingPlot::rescale_drawing();

}
