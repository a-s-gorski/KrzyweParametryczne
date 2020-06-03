
//Łukasz Bondaruk

#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include "Functions.hpp"

class Calculator {

private:
    // How many times Singel calculation was done
    static int operations;
    // increment operations
    void performOperation();
public:
    Calculator();
    ~Calculator();
    // Getter
    int getOperations();
    // Reset Calculator to basic state
    void clearOperations();
    // Calculate using rather X or Y equation
    double calculateSingiel (std::vector<Function<double>*>* function, double t);
    // Make point with x and y
    std::pair<double, double> calculateValue(std::vector<Function<double>*> *x_function, std::vector<Function<double>*> *y_function, double t);
    // Make many points
    std::vector<std::pair<double, double> > calculateSerie(std::vector<Function<double>*> *x_function, std::vector<Function<double>*> *y_function, double left, double right, double points_number);
};


#endif
