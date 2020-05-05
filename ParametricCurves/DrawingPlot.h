#pragma once
// author : Adam Górski

#include <iostream>

#include <vector>
#include <utility>
#include "Frame.h"

using namespace std;


template <class X, class Y>
class DrawingPlot : protected Frame {
protected:
    X** coordinates;
    X X_length_new;
    Y Y_length_new;
    vector <pair <X, Y>> points;
    X x_axis_max, x_axis_min;
    Y y_axis_max, y_axis_min;

public:
    void DrawingPlot<X,Y>::setPlot(vector <pair<X, Y> > values);
    void DrawingPlot<X, Y>::get_edge_values();
    void DrawingPlot<X, Y>::rescale_drawing();
    vector <X [2]> DrawingPlot<X, Y>::getCanvasCoordinates();
    };

