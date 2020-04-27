#include "OutputController.h"
#include "DrawingPlot.h"
#include <QtWidgets/QApplication>
#include <QtWidgets>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#define PI 3.14


using namespace std;







int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QLabel l;
    QPicture pic1;

    vector <pair <double, double> > crds;
    for (int i = 0; i < 100000; i++) {
        pair <double, double> p;
        p.first = cos(i * PI / 180) - pow(cos(2 * i * PI / 180), 3);
        p.second = sin(2 * i * PI / 180) - pow(sin(i * PI / 180), 3);
        //p.first = i * (cos(i * PI / 180) - pow(cos(80 * i * PI / 180), 3));
        //p.second = i * ( sin(i * PI / 180) - pow(sin(80 * i * PI / 180), 3));


        crds.push_back(p);
    }

    DrawingPlot g1(pic1, crds);
    g1.drawPlot();
    

    l.setPicture(pic1);
    l.show();
    return a.exec();
}
