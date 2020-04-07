#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include "functions.hpp"

using namespace std;

class Calculator{

public:
    Calculator();
    ~Calculator();
    pair<double, double> calculate_value(vector<Function*> x_function, vector<Function*> y_function, double t);
    vector<pair<double, double> > calculate_serie(vector<Function*> x_function, vector<Function*> y_function, double left, double right, double points_number);
};


#endif
