#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Plot
{
public:
    vector<pair<double, double>> points;
    Plot(vector<pair<double, double>> vector_values)
    {
        points = vector_values;
    }

    void drawPlot()
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, NULL);
        for (int i = 1; i < points.size(); i++)
        {
            int x_1 = (int)points[i - 1].first;
            int y_1 = (int)points[i - 1].second;
            int x_2 = (int)points[i].first;
            int y_2 = (int)points[i].second;

            line(x_1, y_1, x_2, y_2);
        }
        getch();
        closegraph();
    }
};


