//£ukasz Bondaruk

#include<iostream>
#include<vector>
#include<cmath>
#include "Functions.hpp"

template <class V>
Function<V>::Function(char operation){
#ifdef _DEBUG
    std::cout << "Function: Creating Function\n";
#endif // _DEBUG
    this->parameters_number = 1;

    if (checkOperation(operation)) {
        this->operation = operation;
    }else {
        this->operation = '+';
    }

    this->parameters = { 1 };
}

template <class V>
Function<V>::Function(const Function& func) {
#ifdef _DEBUG
    std::cout << "Function: Copying Function\n";
#endif // _DEBUG
    this->parameters_number = func.parameters_number;
    this->operation = func.operation;
    this->parameters = func.parameters;
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
bool Function<V>::checkOperation(char operation) {
    switch (operation) {
        case '+':
            return true;
        case '-':
            return true;
        case '*':
            return true;
        case '/':
            return true;
        default:
            return false;
    }
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
FCos<V>::FCos(char operation, std::vector<double> parameters){
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
    if (checkOperation(operation)) {
        this->operation = operation;
    }else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    }else {
        this->parameters = { 1, 1, 1 };
    }
}

template <class V>
FCos<V>::FCos(std::vector<double> parameters, char operation) {
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
    if (checkOperation(operation)) {
        this->operation = operation;
    }
    else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    }
    else {
        this->parameters = { 1, 1, 1 };
    }
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

    try {
        result = a * pow(cos(b * t), c);
    }
    catch (...) {
        std::cout << "Illegal mathematical operation";
        result = 0;
    }

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
FSin<V>::FSin(char operation, std::vector<double> parameters) {
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
    if (checkOperation(operation)) {
        this->operation = operation;
    } else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    } else {
        this->parameters = { 1, 1, 1 };
    }
}

template <class V>
FSin<V>::FSin(std::vector<double> parameters, char operation) {
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
    if (checkOperation(operation)) {
        this->operation = operation;
    }
    else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    }
    else {
        this->parameters = { 1, 1, 1 };
    }
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

    try {
        result = a * pow(sin(b * t), c);
    }
    catch (...) {
        std::cout << "Illegal mathematical operation";
        result = 0;
    }

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
FMonomial<V>::FMonomial(char operation, std::vector<double> parameters) {
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
    if (checkOperation(operation)) {
        this->operation = operation;
    } else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    } else {
        this->parameters = { 1, 1, 1 };
    }
}

template <class V>
FMonomial<V>::FMonomial(std::vector<double> parameters, char operation) {
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
    if (checkOperation(operation)) {
        this->operation = operation;
    }
    else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    }
    else {
        this->parameters = { 1, 1, 1 };
    }
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

    try {
        result = a * pow((b + t), c);
    }
    catch (...) {
        std::cout << "Illegal mathematical operation";
        result = 0;
    }

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
FConstant<V>::FConstant(char operation, std::vector<double> parameters) {
#ifdef _DEBUG
    std::cout << "FConstant: Creating FConstant\n";
#endif // _DEBUG
    this->parameters_number = 1;
    /*
        In default:
            a = 1
    */
    if (checkOperation(operation)) {
        this->operation = operation;
    }
    else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    }
    else {
        this->parameters = { 1 };
    }
}

template <class V>
FConstant<V>::FConstant(std::vector<double> parameters, char operation) {
#ifdef _DEBUG
    std::cout << "FConstant: Creating FConstant\n";
#endif // _DEBUG
    this->parameters_number = 1;
    /*
        In default:
            a = 1
    */
    if (checkOperation(operation)) {
        this->operation = operation;
    }
    else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    }
    else {
        this->parameters = { 1 };
    }
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

    try {
        result = a;
    }
    catch (...) {
        std::cout << "Illegal mathematical operation";
        result = 0;
    }

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

template <class V>
FExp<V>::FExp(char operation, std::vector<double> parameters) {
#ifdef _DEBUG
    std::cout << "FExp: Creating FExp\n";
#endif // _DEBUG
    this->parameters_number = 2;
    /*
        In default:
            a = 1
            b = e
    */
    if (checkOperation(operation)) {
        this->operation = operation;
    }
    else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    }
    else {
        this->parameters = { 1, 2.7183 };
    }
}

template <class V>
FExp<V>::FExp(std::vector<double> parameters, char operation) {
#ifdef _DEBUG
    std::cout << "FExp: Creating FExp\n";
#endif // _DEBUG
    this->parameters_number = 2;
    /*
        In default:
            a = 1
            b = e
    */
    if (checkOperation(operation)) {
        this->operation = operation;
    }
    else {
        this->operation = '+';
    }

    if (checkParameters(parameters)) {
        this->parameters = parameters;
    }
    else {
        this->parameters = { 1, 2.7183 };
    }
}

template <class V>
FExp<V>::~FExp() {
#ifdef _DEBUG
    std::cout << "FExp: Destroying FExp\n";
#endif // _DEBUG
}

template <class V>
bool FExp<V>::checkParameters(std::vector<V> new_parameters) {

#ifdef _DEBUG
    std::cout << "FExp: Checking parameters\n";
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

    if (new_parameters[1] == 0 || new_parameters[1] == 1)
        return false;

    return true;
}

template <class V>
double FExp<V>::calculateValue(V t) {
#ifdef _DEBUG
    std::cout << "FExp: Count value of t\n";
    std::cout << "   FExp(t) = a*(b)^t\n";
#endif // _DEBUG

    double& a = this->parameters[0];
    double& b = this->parameters[1];

    double result;

    try {
        result = a*pow(b, t);
    }
    catch (...) {
        std::cout << "Illegal mathematical operation";
        result = 0;
    }

#ifdef _DEBUG
    std::cout << "   a: " << a << " b: " << b << "\n";
    std::cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}

template <class V>
void FExp<V>::showFunction(const bool not_first) {

    double& a = this->parameters[0];
    double& b = this->parameters[1];

    if (not_first) {
        std::cout << this->operation << " ";
    }
    if (a == 1) {}
    else
        std::cout << a << '*';
    cout << "(";
    if (abs(b - 2.7183 <= 0.001)) {
        std::cout << "e";
    }
    else {
        std::cout << b;
    }
    std::cout << ")^(t) ";
}



