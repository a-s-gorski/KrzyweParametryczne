#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <iostream>
#include <vector>
#include "../Funkcje/Functions.hpp"


using namespace std;


class Equation {
public:
    vector<Function*> equation;
    Equation();
    void printEquation();
    void addComponent();
    ~Equation();
};


class InputController {
    int number_of_points;
    double left_border;
    double right_border;
    Equation X;
    Equation Y;
    void addToEquation(Equation* Eq);

public:
    InputController();
    void getInput();
    void printEquations();
    int getNumberOfPoints();
    double getLeftBorder();
    double getRightBorder();
    Equation* getXEquation();
    Equation* getYEquation();
    ~InputController();
};
#endif