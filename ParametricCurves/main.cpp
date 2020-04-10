#include <iostream>
#include <cmath>
#include <vector>
#include "Functions.hpp"
#include "Calculator.hpp"
#include "InputController.hpp"

using namespace std;

int main()
{
    //Make a class from this to menage process

    //Prepare input
    InputController console_input;

    console_input.getInput();

    Equation x = console_input.getXEquation();
    Equation y = console_input.getYEquation();
    vector<Function*> x_func = x.getEquation();
    vector<Function*> y_func = y.getEquation();

    double left_border = console_input.getLeftBorder();
    double right_border = console_input.getRightBorder();
    int points_number = console_input.getNumberOfPoints();

    //Calculate points
    Calculator cal;

    vector <pair <double, double> > points = cal.calculateSerie(&x_func, &y_func, left_border, right_border, points_number);

    //Present output
}
