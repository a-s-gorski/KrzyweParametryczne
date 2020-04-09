#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <iostream>
#include <vector>
#include "Functions.hpp"


using namespace std;


class Equation {
public:
    vector<Function*> equation;
    Equation();
    void printEquation();
    ~Equation();
};


class InputController {
    int number_of_points;
    double left_border;
    double right_border;
    Equation X;
    Equation Y;
    void addComponents(Equation Eq);

public:
    InputController();
    void getInput();
    void printEquations();
    ~InputController();
};
#endif