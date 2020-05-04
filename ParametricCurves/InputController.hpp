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
    void operator += (Function* func);
    const std::vector<Function*>& getEquation();
    ~Equation();
};


class InputController {
    Function* createFunction(int iterator);
    void getFieldOfPointsToDraw();
    void addToEquation(Equation* Eq);
protected:
    int number_of_points;
    double left_border;
    double right_border;
    Equation X;
    Equation Y;
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


class CommandLineInput : public InputController {
    Function* addToEquation(Equation* Eq, char operation, int function, double a, double b, double c);
    Function* addToEquation(Equation* Eq, char operation, double a);
public:
    CommandLineInput();
    void getInput(std::string filename);
    ~CommandLineInput();
};
#endif
