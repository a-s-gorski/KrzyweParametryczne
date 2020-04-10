#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include "Functions.hpp"

using namespace std;

class Calculator {

public:
    Calculator();
    ~Calculator();
    pair<double, double> calculateValue(vector<Function*> *x_function, vector<Function*> *y_function, double t);
    vector<pair<double, double> > calculateSerie(vector<Function*> *x_function, vector<Function*> *y_function, double left, double right, double points_number);
};


#endif
