#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include "Functions.hpp"

class Calculator {

public:
    Calculator();
    ~Calculator();
    double calculateSingiel (std::vector<Function*>* function, double t);
    std::pair<double, double> calculateValue(std::vector<Function*> *x_function, std::vector<Function*> *y_function, double t);
    std::vector<std::pair<double, double> > calculateSerie(std::vector<Function*> *x_function, std::vector<Function*> *y_function, double left, double right, double points_number);
};


#endif
