// Autor :  Adam Górski

#include "DrawingPlot.h"
//#include <QtWidgets/QApplication>
//#include <QtWidgets>
#include <iostream>
#include <vector>
#include <utility>
#include "Frame.h"

using namespace std;

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


/*
There is no error in the following piece of code:

float arr[4];
arr[0] = 6.28;
arr[1] = 2.50;
arr[2] = 9.73;
arr[3] = 4.364;
std::vector<float*> vec = std::vector<float*>();
vec.push_back(arr);
float* ptr = vec.front();
\
*/


template <class X, class Y>
vector <X> DrawingPlot<X, Y>::getCanvasCoordinates() {
	// vector <X[2]> coordinates_pair;
	X array[DrawingPlot::points.size][2];

	for(int i = 0; i < DrawingPlot::points.size; i++) {
		array[i][0] = *DrawingPlot::coordinates[0];
		array[i][1] = *DrawingPlot::coordinates[1];
	}
	vector<X*> coordinates_pair = vector<X*>;
	for(int i = 0; i < DrawingPlot::points.size; i++) {
		coordinates_pair.push_back(array[i])
	}
	X* ptr = coordinates_pair.front();

	return coordinates_pair;

}

template <class X, class Y>
int DrawingPlot<X, Y>::getPointsNumber() {
	int size = (int)DrawingPlot::points.size();
	return size;
}

template <class X, class Y>

X DrawingPlot<X, Y>::getCurrentCoordinates(int row, int col) {
	X value = coordinates[row][col];
	return value;
}