#include <iostream>
#ifndef QT_H
#define QT_H
#include <cmath>
#include <vector>
#include "Functions.hpp"
#include "Calculator.hpp"
#include "InputController.hpp"
#include "OutputController.h"
#include "DrawingPlot.h"
#include "DrawingPlot.cpp"
//#include "DrawingPlotGui.h"
//#include "DrawingPlotGui.cpp"
//#include <QtWidgets/QApplication>
//#include <QtWidgets>
#include <utility>
#include <math.h>
#include "Frame.h"
// #define PI 3.14


using namespace std;

int main(int argc, char* argv[])
{
    //Make a class from this to menage process

    InputController* console_input = chooseInput();

    Equation<Function<double>>& x = console_input->getXEquation();
    Equation<Function<double>>& y = console_input->getYEquation();
    vector<Function<double>*> x_func = x.getEquation();
    vector<Function<double>*> y_func = y.getEquation();

    double left_border = console_input->getLeftBorder();
    double right_border = console_input->getRightBorder();
    int points_number = console_input->getNumberOfPoints();

    //Calculate points
    Calculator cal;

    vector <pair <double, double> > test_points = cal.calculateSerie(&x_func, &y_func, left_border, right_border, points_number);

    //Present output
    // QApplication a(argc, argv);
    //QLabel l;
    //QPicture pic1;
    // used to create basic tests for only OutputController without commandline InputController
   // for (int i = 0; i < 100000; i++) {
       // pair <double, double> p;
       // p.first = cos(i * PI / 180) - pow(cos(2 * i * PI / 180), 3);
       // p.second = sin(2 * i * PI / 180) - pow(sin(i * PI / 180), 3);
        //p.first = i * (cos(i * PI / 180) - pow(cos(80 * i * PI / 180), 3));
        //p.second = i * ( sin(i * PI / 180) - pow(sin(80 * i * PI / 180), 3));


        //crds.push_back(p);
    //}

    //DrawingPlotGui<double, double> g1;
    //g1.setPicture(pic1);
    //g1.setPlot(test_points);
    //g1.drawPlot();

    DrawingPlot<double, double> g1;
    //g1.setPicture(pic1);
    g1.setPlot(test_points);


    //l.setPicture(pic1);
    //l.show();
    //return a.exec();

    delete console_input;

    return 0;
}
#endif