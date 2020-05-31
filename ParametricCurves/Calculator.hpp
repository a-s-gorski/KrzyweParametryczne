
//Łukasz Bondaruk

#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include "Functions.hpp"

class Calculator {

private:
    static int operations;
    void performOperation();
public:
    Calculator();
    ~Calculator();
    int getOperations();
    void clearOperations();
    double calculateSingiel (std::vector<Function<double>*>* function, double t);
    std::pair<double, double> calculateValue(std::vector<Function<double>*> *x_function, std::vector<Function<double>*> *y_function, double t);
    std::vector<std::pair<double, double> > calculateSerie(std::vector<Function<double>*> *x_function, std::vector<Function<double>*> *y_function, double left, double right, double points_number);
};


#endif
