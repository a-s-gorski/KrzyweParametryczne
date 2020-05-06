
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


template <class V>
Function<V>::Function() {
#ifdef _DEBUG
    std::cout << "Function: Creating Function\n";
#endif // _DEBUG
    this->parameters_number = 1;
    this->operation = '+';
}

template <class V>
Function<V>::~Function() {
#ifdef _DEBUG
    std::cout << "Function: Destroying Function\n";
#endif // _DEBUG
}

template <class V>
void Function<V>::setParameters(std::vector<V> new_parameters) {
#ifdef _DEBUG
    std::cout << "Function: New parameters\n";
    for (int i = 0; i < this->parameters_number; i++) {
        std::cout << "   " << i << " : " << new_parameters[i] << "\n";
    }
#endif // _DEBUG
    this->parameters = new_parameters;
    this->operation = '+';

}

template <class V>
void Function<V>::setOperation(char new_operation) {
    this->operation = new_operation;
}

template <class V>
char Function<V>::getOperation() {
    return this->operation;
}

template <class V>
double Function<V>::operator ()(V t) {
    return this->calculateValue(t);
}


template <class V>
FCos<V>::FCos() {
#ifdef _DEBUG
    std::cout << "FCos: Creating FCos\n";
#endif // _DEBUG
    this->parameters_number = 3;
    /*
        In default:
            a = 1
            b = 1
            c = 1
    */
    this->parameters.push_back(1);
    this->parameters.push_back(1);
    this->parameters.push_back(1);
}

template <class V>
FCos<V>::~FCos() {
#ifdef _DEBUG
    std::cout << "FCos: Destroying FCos\n";
#endif // _DEBUG
}

template <class V>
bool FCos<V>::checkParameters(std::vector<V> new_parameters) {

#ifdef _DEBUG
    std::cout << "FCos: Checking parameters\n";
    for (double new_parameter : new_parameters)
    {
        std::cout << new_parameter << " ";
    }
    std::cout << "\n";
#endif // _DEBUG
    //Check if parameters are good

    if (new_parameters.size() != this->parameters_number)
        return false;

    if (new_parameters[0] == 0)
        return false;

    if (new_parameters[1] == 0)
        return false;

    if (new_parameters[2] == 0)
        return false;

    return true;
}

template <class V>
double FCos<V>::calculateValue(V t) {
#ifdef _DEBUG
    std::cout << "FCos: Count value of t\n";
    std::cout << "   Cos(t) = a*cos(b*t)^c\n";
#endif // _DEBUG

    double& a = this->parameters[0];
    double& b = this->parameters[1];
    double& c = this->parameters[2];

    double result;

    result = a * pow(cos(b * t), c);

#ifdef _DEBUG
    std::cout << "   a: " << a << " b: " << b << " c: " << c << "\n";
    std::cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}

template <class V>
void FCos<V>::showFunction(const bool not_first) {

    double& a = this->parameters[0];
    double& b = this->parameters[1];
    double& c = this->parameters[2];

    if (not_first) {
        std::cout << this->operation << " ";
    }
    if (a == 1) {}
    else if (a == -1)
        std::cout << '-';
    else
        std::cout << a << '*';
    std::cout << "cos(";
    if (b == 1) {}
    else if (b == -1)
        std::cout << "-";
    else
        std::cout << b << "*";
    std::cout << "t)";
    if (c == 1) {}
    else if (c < 0)
        std::cout << "^(" << c << ")";
    else
        std::cout << "^" << c;
    std::cout << " ";
}


template <class V>
FSin<V>::FSin() {
#ifdef _DEBUG
    std::cout << "FSin: Creating FSin\n";
#endif // _DEBUG
    this->parameters_number = 3;
    /*
        In default:
            a = 1
            b = 1
            c = 1
    */
    this->parameters.push_back(1);
    this->parameters.push_back(1);
    this->parameters.push_back(1);
}

template <class V>
FSin<V>::~FSin() {
#ifdef _DEBUG
    std::cout << "FSin: Destroying FSin\n";
#endif // _DEBUG
}

template <class V>
bool FSin<V>::checkParameters(std::vector<V> new_parameters) {

#ifdef _DEBUG
    std::cout << "FSin: Checking parameters\n";
    for (int i = 0; i < new_parameters.size(); i++) {
        std::cout << new_parameters[i] << " ";
    }
    std::cout << "\n";
#endif // _DEBUG
    //Check if parameters are good

    if (new_parameters.size() != this->parameters_number)
        return false;

    if (new_parameters[0] == 0)
        return false;

    if (new_parameters[1] == 0)
        return false;

    if (new_parameters[2] == 0)
        return false;

    return true;
}

template <class V>
double FSin<V>::calculateValue(V t) {
#ifdef _DEBUG
    std::cout << "FSin: Count value of t\n";
    std::cout << "   Sin(t) = a*sin(b*t)^c\n";
#endif // _DEBUG

    double& a = this->parameters[0];
    double& b = this->parameters[1];
    double& c = this->parameters[2];

    double result;

    result = a * pow(sin(b * t), c);

#ifdef _DEBUG
    std::cout << "   a: " << a << " b: " << b << " c: " << c << "\n";
    std::cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}

template <class V>
void FSin<V>::showFunction(const bool not_first) {

    double& a = this->parameters[0];
    double& b = this->parameters[1];
    double& c = this->parameters[2];

    if (not_first) {
        std::cout << this->operation << " ";
    }
    if (a == 1) {}
    else if (a == -1)
        std::cout << '-';
    else
        std::cout << a << '*';
    std::cout << "sin(";
    if (b == 1) {}
    else if (b == -1)
        std::cout << "-";
    else
        std::cout << b << "*";
    std::cout << "t)";
    if (c == 1) {}
    else if (c < 0)
        std::cout << "^(" << c << ")";
    else
        std::cout << "^" << c;
    std::cout << " ";
}

template <class V>
FMonomial<V>::FMonomial() {
#ifdef _DEBUG
    std::cout << "FMonomial: Creating FMonomial\n";
#endif // _DEBUG
    this->parameters_number = 3;
    /*
        In default:
            a = 1
            b = 1
            c = 1
    */
    this->parameters.push_back(1);
    this->parameters.push_back(1);
    this->parameters.push_back(1);
}

template <class V>
FMonomial<V>::~FMonomial() {
#ifdef _DEBUG
    std::cout << "FMonomial: Destroying FMonomial\n";
#endif // _DEBUG
}

template <class V>
bool FMonomial<V>::checkParameters(std::vector<V> new_parameters) {

#ifdef _DEBUG
    std::cout << "FMonomial: Checking parameters\n";
    for (int i = 0; i < new_parameters.size(); i++) {
        std::cout << new_parameters[i] << " ";
    }
    std::cout << "\n";
#endif // _DEBUG
    //Check if parameters are good

    if (new_parameters.size() != this->parameters_number)
        return false;

    if (new_parameters[0] == 0)
        return false;

    if (new_parameters[2] == 0)
        return false;

    return true;
}

template <class V>
double FMonomial<V>::calculateValue(V t) {
#ifdef _DEBUG
    std::cout << "FMonomial: Count value of t\n";
    std::cout << "   Monomial(t) = a*(b+t)^c\n";
#endif // _DEBUG

    double& a = this->parameters[0];
    double& b = this->parameters[1];
    double& c = this->parameters[2];

    double result;

    result = a * pow((b + t), c);

#ifdef _DEBUG
    std::cout << "   a: " << a << " b: " << b << " c: " << c << "\n";
    std::cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}

template <class V>
void FMonomial<V>::showFunction(const bool not_first) {

    double& a = this->parameters[0];
    double& b = this->parameters[1];
    double& c = this->parameters[2];

    if (not_first) {
        std::cout << this->operation << " ";
    }
    if (a == 1) {}
    else
        std::cout << a << '*';
    if (b == 0)
        std::cout << "(t)";
    else
        std::cout << "(" << b << '+' << "t)";
    if (c == 1) {}
    else if (c < 0)
        std::cout << "^(" << c << ")";
    else
        std::cout << "^" << c;
    std::cout << " ";
}

template <class V>
FConstant<V>::FConstant() {
#ifdef _DEBUG
    std::cout << "FConstant: Creating FConstant\n";
#endif // _DEBUG
    this->parameters_number = 1;
    /*
        In default:
            a = 1
    */
    this->parameters.push_back(1);
}

template <class V>
FConstant<V>::~FConstant() {
#ifdef _DEBUG
    std::cout << "FConstant: Destroying FConstant\n";
#endif // _DEBUG
}

template <class V>
bool FConstant<V>::checkParameters(std::vector<V> new_parameters) {

#ifdef _DEBUG
    std::cout << "FConstant: Checking parameters\n";
    for (int i = 0; i < new_parameters.size(); i++) {
        std::cout << new_parameters[i] << " ";
    }
    std::cout << "\n";
#endif // _DEBUG
    //Check if parameters are good

    if (new_parameters.size() != this->parameters_number)
        return false;

    if (new_parameters[0] == 0)
        return false;

    return true;
}

template <class V>
double FConstant<V>::calculateValue(V t) {
#ifdef _DEBUG
    std::cout << "FConstant: Count value of t\n";
    std::cout << "   Constant(t) = a\n";
#endif // _DEBUG

    double& a = this->parameters[0];

    double result;

    result = a;

#ifdef _DEBUG
    std::cout << "   a: " << a << "\n";
    std::cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}

template <class V>
void FConstant<V>::showFunction(const bool not_first) {

    double& a = this->parameters[0];

    if (not_first) {
        std::cout << this->operation << " ";
    }
    std::cout << a << " ";
}
#endif