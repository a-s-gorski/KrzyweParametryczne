
//Łukasz Bondaruk

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<vector>
#include <math.h>

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
    friend bool operator==(Function<V>& lhs, Function<V>& rhs) {
        const type_info& tl = typeid(lhs);
        const type_info& tr = typeid(rhs);
        if (tl != tr)
            return false;
        if(lhs.operation != rhs.operation)
            return false;
        if (lhs.parameters != rhs.parameters)
            return false;
        return true;
    };
    friend std::ostream& operator<<(std::ostream& os, const Function& func) {
        os << func.operation << " ";
        os << "Function" << " ";
        for (int i = 0; i < func.parameters_number; i++) {
            os << func.parameters[i] << " ";
        }
        return os;
    };
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
    FCos(std::vector<double> parameters = std::vector<double>{ 1, 1, 1 }, char operation = '+');
    ~FCos();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
    friend std::ostream& operator<<(std::ostream& os, const FCos<V>& func) {
        os << func.operation << " ";
        os << "FCos" << " ";
        for (int i=0; i < func.parameters_number; i++) {
            os << func.parameters[i] << " ";
        }
        return os;
    };
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
    FSin(std::vector<double> parameters = std::vector<double>{ 1, 1, 1 }, char operation = '+');
    ~FSin();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
    friend std::ostream& operator<<(std::ostream& os, const FSin<V>& func) {
        os << func.operation << " ";
        os << "FSin" << " ";
        for (int i = 0; i < func.parameters_number; i++) {
            os << func.parameters[i] << " ";
        }
        return os;
    };
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
    FMonomial(std::vector<double> parameters = std::vector<double>{ 1, 1, 1 }, char operation = '+');
    ~FMonomial();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
    friend std::ostream& operator<<(std::ostream& os, const FMonomial<V>& func) {
        os << func.operation << " ";
        os << "FMonomial" << " ";
        for (int i = 0; i < func.parameters_number; i++) {
            os << func.parameters[i] << " ";
        }
        return os;
    };
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
    FConstant(std::vector<double> parameters = std::vector<double>{ 1 }, char operation = '+');
    ~FConstant();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
    friend std::ostream& operator<<(std::ostream& os, const FConstant<V>& func) {
        os << func.operation << " ";
        os << "FConstant" << " ";
        for (int i = 0; i < func.parameters_number; i++) {
            os << func.parameters[i] << " ";
        }
        return os;
    };
};

template <class V = double>
class FExp : public Function <V> {
    /*
        Exp(t) = a*(b)^t
        parameters_number: 2
        parameters: a, b
            a!=0
            b!=0 b!=1
    */
public:
    FExp(std::vector<double> parameters = std::vector<double>{ 1, 2.7183 }, char operation = '+');
    ~FExp();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
    friend std::ostream& operator<<(std::ostream& os, const FExp<V>& func) {
        os << func.operation << " ";
        os << "FExp" << " ";
        for (int i = 0; i < func.parameters_number; i++) {
            os << func.parameters[i] << " ";
        }
        return os;
    };
};

template <class V = double>
class FLog : public Function <V> {
    /*
        Log(t) = log_a(t)
        parameters_number: 1
        parameters: a
            a!=1 a>0
    */
public:
    FLog(std::vector<double> parameters = std::vector<double>{ 2.7183 }, char operation = '+');
    ~FLog();
    bool checkParameters(std::vector<V> parameters);
    double calculateValue(V t);
    void showFunction(bool not_first);
    friend std::ostream& operator<<(std::ostream& os, const FLog<V>& func) {
        os << func.operation << " ";
        os << "FLog" << " ";
        for (int i = 0; i < func.parameters_number; i++) {
            os << func.parameters[i] << " ";
        }
        return os;
    };
};
#endif