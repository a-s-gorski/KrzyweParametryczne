#pragma once

#include <QtWidgets>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;


class DrawingPlot {
private:
    double screen_height = 800.0;
    double screen_width = 1200.0;
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
    DrawingPlot(QPicture picture_base, vector <pair <double, double>> values) {
        DrawingPlot::drawingPanel = picture_base;
        DrawingPlot::points = values;

        DrawingPlot::coordinates = new double* [DrawingPlot::points.size()];
        for (int i = 0; i < DrawingPlot::points.size(); i++) {
            DrawingPlot::coordinates[i] = new double[2];
        }
    DrawingPlot::get_edge_values();
    DrawingPlot::rescale_drawing();
    }
    ~DrawingPlot();
    virtual void drawPlot();
    };