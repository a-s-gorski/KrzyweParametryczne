#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <iostream>
#include <vector>
#include "Functions.hpp"


using namespace std;


class Equation {
    vector<Function*> equation;
public:
    Equation();
    void printEquation() const;
    void addElementCos(double a, double b, double c);
    void addElementSin(double a, double b, double c);
    const vector<Function*>& getEquation();
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
    void printEquations() const;
    int getNumberOfPoints();
    double getLeftBorder();
    double getRightBorder();
    Equation& getXEquation();
    Equation& getYEquation();
    ~InputController();
    friend void testInput(InputController); // friend function used for Unit Tets
};
#endif
