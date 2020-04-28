//Bondaruk £ukasz

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include "Functions.hpp"
#include "Calculator.hpp"

using namespace std;

Calculator::Calculator() {
#ifdef _DEBUG
    cout << "Calculator: Creating Calculator\n";
#endif // _DEBUG
}

Calculator::~Calculator() {
#ifdef _DEBUG
    cout << "Calculator: Destroying Calculator\n";
#endif // _DEBUG
}

pair<double, double> Calculator::calculateValue(vector<Function*> *x_function, vector<Function*> *y_function, double t) {
#ifdef _DEBUG
    cout << "Calculator: Calculate value for: " << t << "\n";
#endif // _DEBUG

    double x = 0;
    double y = 0;

    for (auto& i : (*x_function))
    {
        x += (*i).calculateValue(t);
    }

    for (int i = 0; i < (*y_function).size(); i++) {
        y += (*(*y_function)[i]).calculateValue(t);
    }

    pair<double, double> point = make_pair(x, y);

    return point;
}

vector<pair<double, double> > Calculator::calculateSerie(vector<Function*> *x_function, vector<Function*> *y_function, double left, double right, double points_number) {
#ifdef _DEBUG
    cout << "Calculator: Calculate " << points_number << " points, from: " << left << " to: " << right << "\n";
#endif // _DEBUG

    vector< pair <double, double> > points;

    if (points_number == 1) {
        points.push_back(calculateValue(x_function, y_function, left));
    }
    else {
        double step = (right - left) / (points_number - 1);

        for (double i = left; i <= right; i += step) {
            pair<double, double> point = calculateValue(x_function, y_function, i);
            points.push_back(point);
        }
    }



    // sort(points.begin(), points.end());

    return points;

}
