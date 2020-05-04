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

double Calculator::calculateSingiel(vector<Function<double>*>* function, double t) {

    double *values = new double[(*function).size()];
    double v = 0;

    int it = 0;
    for (auto& i : (*function))
    {
        values[it++] = (*i)(t);
    }

    it = 0;
    double cur = 0;
    for (auto& i : (*function))
    {
        char o = (*i).getOperation();

        if (o == '+' || o == '-') {
            v += cur;
            cur = values[it++];

            if (o == '-')
                cur *= -1;
        }
        else if (o == '*') {
            cur *= values[it++];
        }
        else if (o == '/') {
            if (values[it] == 0) {
                it++;
            }
            else {
                cur /= values[it++];
            }
        }
    }

    v += cur;

    delete[] values;

    return v;
}

pair<double, double> Calculator::calculateValue(vector<Function<double>*> *x_function, vector<Function<double>*> *y_function, double t) {
#ifdef _DEBUG
    cout << "Calculator: Calculate value for: " << t << "\n";
#endif // _DEBUG

    double x = calculateSingiel(x_function, t);
    double y = calculateSingiel(y_function, t);

    pair<double, double> point = make_pair(x, y);

    return point;
}

vector<pair<double, double> > Calculator::calculateSerie(vector<Function<double>*> *x_function, vector<Function<double>*> *y_function, double left, double right, double points_number) {
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
