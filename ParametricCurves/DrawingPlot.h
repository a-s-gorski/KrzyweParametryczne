#pragma once
// author : Adam Górski

#include <QtWidgets>
#include <iostream>
#include <vector>
#include <utility>
#include "Frame.h"

using namespace std;

template <class X, class Y>
class DrawingPlot : private Frame {
protected:
    X** coordinates;
    X X_length_new;
    Y Y_length_new;
    vector <pair <X, Y>> points;
    QPicture drawingPanel;
    X x_axis_max, x_axis_min;
    Y y_axis_max, y_axis_min;


public:
    void DrawingPlot<X,Y>::drawPlot();
    void DrawingPlot<X,Y>::setPicture(QPicture picture_base);
    void DrawingPlot<X,Y>::setPlot(vector <pair<X, Y> > values);
    void DrawingPlot<X, Y>::get_edge_values();
    void DrawingPlot<X, Y>::rescale_drawing();


    };