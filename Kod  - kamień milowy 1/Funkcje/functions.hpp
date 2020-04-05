#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>

using namespace std;

class Function{
protected:
    int parameters_number;
    double *parameters;
public:
    virtual ~Function();
    virtual bool check_parameters(double parameters[])=0;
    virtual void set_parameters(double parameters[]);
    virtual double calculate_value(double t)=0;
};

class FCos: public Function{
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
    bool check_parameters(double new_parameters[]);
    double calculate_value(double t);
};

class FSin: public Function{
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
    bool check_parameters(double new_parameters[]);
    double calculate_value(double t);
};
#endif
