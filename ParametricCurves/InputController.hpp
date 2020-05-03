// Andrzej Kusiak
#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <iostream>
#include <vector>
#include "Functions.hpp"



class Equation {
    std::vector<Function*> equation;
public:
    Equation();
    void printEquation() const;
    void operator += (int func_type);
    void setOperation(char c);
    const std::vector<Function*>& getEquation();
    ~Equation();
};


class InputController {
    int number_of_points;
    double left_border;
    double right_border;
    Equation X;
    Equation Y;
    void addToEquation(Equation* Eq);
    void printEquations() const;

public:
    InputController();
    void getInput();
    int getNumberOfPoints();
    double getLeftBorder();
    double getRightBorder();
    Equation& getXEquation();
    Equation& getYEquation();
    ~InputController();
};
#endif
