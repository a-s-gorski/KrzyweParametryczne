#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<vector>

class Function {
protected:
    int parameters_number;  // brak inicjalizacji !!! np. w konstruktorze)
    std::vector<double> parameters;
public:
    virtual ~Function();
    virtual bool checkParameters(std::vector<double> parameters) = 0;
    virtual void setParameters(std::vector<double> parameters);
    virtual double calculateValue(double t) = 0;
    virtual void showFunction(bool not_first) = 0;
   // operator() ??
};

class FCos : public Function {
    /*
        Cos(t) = a*cos(b*t)^c
        parameters_number: 3
        parameters: a,b,c
            a!=0
            b!=0
            c!=0
    */
public:
    FCos();
    ~FCos();
    bool checkParameters(std::vector<double> parameters);
    double calculateValue(double t);
    void showFunction(bool not_first);
};

class FSin : public Function {
    /*
        Sin(t) = a*sin(b*t)^c
        parameters_number: 3
        parameters: a,b,c
            a!=0
            b!=0
            c!=0
    */
public:
    FSin();
    ~FSin();
    bool checkParameters(std::vector<double> parameters);
    double calculateValue(double t);
    void showFunction(bool not_first);
};
#endif
