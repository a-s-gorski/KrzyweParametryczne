#pragma once
// author : Adam Górski

#include <QtWidgets>
#include <iostream>
#include <vector>
#include <utility>
#include "Frame.h"

using namespace std;


class DrawingPlot : private Frame {
protected:
    //double screen_height = 400.0;
    //double screen_width = 600.0;
    double** coordinates;
    double X_length_new;
    double Y_length_new;

    vector <pair <double, double>> points;
    QPicture drawingPanel;
    double x_axis_max, x_axis_min;
    double y_axis_max, y_axis_min;

    virtual void get_edge_values();
    virtual void rescale_drawing();


public:
    DrawingPlot();
    ~DrawingPlot();
    virtual void drawPlot();
    void setPicture(QPicture picture_base);
    void setPlot(vector <pair<double, double> > values);

    };