// Andrzej Kusiak
#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <iostream>
#include <vector>
#include "Functions.hpp"
#include "Equation.hpp"


class InputController {
protected:
    int number_of_points;
    double left_border;
    double right_border;
    Equation<Function<double>> X;
    Equation<Function<double>> Y;
    virtual void setNumberOfPoints() = 0;
    virtual void setBorders() = 0;
    virtual void setXEquation() = 0;
    virtual void setYEquation() = 0;
    virtual Function<double>* createFunction(int iterator) = 0;

public:
    InputController();
    virtual void getInput();
    int getNumberOfPoints();
    double getLeftBorder();
    double getRightBorder();
    Equation<Function<double>>& getXEquation();
    Equation<Function<double>>& getYEquation();
    virtual ~InputController();
};


class CMDInput : public InputController {
private:
    void setNumberOfPoints();
    void setBorders();
    void setXEquation();
    void setYEquation();
    virtual Function<double>* createFunction(int iterator);

public:
    CMDInput();
    ~CMDInput();
    friend std::ostream& operator<<(std::ostream& os, CMDInput& ob);
};


class FileInput : public InputController {
    Function<double>* addToEquation(Equation<Function<double>>* Eq, char operation, int function, double a, double b, double c);
    Function<double>* addToEquation(Equation<Function<double>>* Eq, char operation, double a);
public:
    FileInput();
    void getInput(std::string filename);
    ~FileInput();
};
#endif