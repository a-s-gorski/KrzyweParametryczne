
//Łukasz Bondaruk

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<vector>
#include<cmath>

template <class V>
class Function {
protected:
    int parameters_number;
    char operation;
    std::vector<V> parameters;
public:
    Function();
    virtual ~Function();
    void setOperation(char new_operation);
    char getOperation();
    virtual bool checkParameters(std::vector<V> parameters) = 0;
    virtual void setParameters(std::vector<V> parameters);
    virtual double calculateValue(V t) = 0;
    virtual void showFunction(bool not_first) = 0;
    double operator()(V t);
};

template <class V>
class FCos : public Function <V> {
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
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
};

template <class V>
class FSin : public Function <V> {
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
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
};

template <class V>
class FMonomial : public Function <V> {
    /*
        Monomial(t) = a*(b+t)^c
        parameters_number: 3
        parameters: a,b,c
            a!=0
            c!=0
    */
public:
    FMonomial();
    ~FMonomial();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
};

template <class V>
class FConstant : public Function <V> {
    /*
        Constant(t) = a
        parameters_number: 1
        parameters: a
            a!=0
    */
public:
    FConstant();
    ~FConstant();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
};

#endif