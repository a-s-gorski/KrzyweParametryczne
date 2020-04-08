#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<vector>

using namespace std;

class Function{
protected:
    int parameters_number;
    vector<double> parameters;
public:
    virtual ~Function();
    virtual bool checkParameters(vector<double> parameters)=0;
    virtual void setParameters(vector<double> parameters);
    virtual double calculateValue(double t)=0;
    virtual void showFunction()=0;
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
    bool checkParameters(vector<double> parameters);
    double calculateValue(double t);
    void showFunction();
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
    bool checkParameters(vector<double> parameters);
    double calculateValue(double t);
    void showFunction();
};
#endif
