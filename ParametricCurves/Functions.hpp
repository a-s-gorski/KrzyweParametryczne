
//Łukasz Bondaruk

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<vector>
#include<cmath>

template <class V = double>
class Function {
protected:
    int parameters_number;
    char operation;
    std::vector<V> parameters;
public:
    Function(char operation = '+');
    Function(const Function& func);
    virtual ~Function();
    void setOperation(char new_operation);
    bool checkOperation(char operation);
    char getOperation();
    virtual bool checkParameters(std::vector<V> parameters) = 0;
    virtual void setParameters(std::vector<V> parameters);
    virtual double calculateValue(V t) = 0;
    virtual void showFunction(bool not_first) = 0;
    double operator()(V t);
};

template <class V = double>
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
    FCos(char operation = '+', std::vector<double> parameters = std::vector<double>{ 1, 1, 1 });
    ~FCos();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
};

template <class V = double>
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
    FSin(char operation = '+', std::vector<double> parameters = std::vector<double>{ 1, 1, 1 });
    ~FSin();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
};

template <class V = double>
class FMonomial : public Function <V> {
    /*
        Monomial(t) = a*(b+t)^c
        parameters_number: 3
        parameters: a,b,c
            a!=0
            c!=0
    */
public:
    FMonomial(char operation = '+', std::vector<double> parameters = std::vector<double>{ 1, 1, 1 });
    ~FMonomial();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
};

template <class V = double>
class FConstant : public Function <V> {
    /*
        Constant(t) = a
        parameters_number: 1
        parameters: a
            a!=0
    */
public:
    FConstant(char operation = '+', std::vector<double> parameters = std::vector<double>{ 1 });
    ~FConstant();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
};

#endif