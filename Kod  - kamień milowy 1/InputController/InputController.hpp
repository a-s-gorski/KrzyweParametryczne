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
public:
    int number_of_points;
    double left_border;
    double right_border;
    Equation X;
    Equation Y;

    InputController();
    void getInput();
    void printEquations();
    ~InputController();
};
