//Autor

#include<iostream>
#include<cmath>
#include "Functions.hpp"

using namespace std;

Function::Function() {
#ifdef _DEBUG
    cout << "Function: Creating Function\n";
#endif // _DEBUG
    parameters_number = 1;
    operation = '+';
}

Function::~Function() {
#ifdef _DEBUG
    cout << "Function: Destroying Function\n";
#endif // _DEBUG
}

void Function::setParameters(vector<double> new_parameters) {
#ifdef _DEBUG
    cout << "Function: New parameters\n";
    for (int i = 0; i < parameters_number; i++) {
        cout << "   " << i << " : " << new_parameters[i] << "\n";
    }
#endif // _DEBUG
    parameters = new_parameters;
    operation = '+';

}

void Function::setOperation(char new_operation) {
    operation = new_operation;
}

char Function::getOperation() {
    return operation;
}

double Function::operator ()(double t) {
    return calculateValue(t);
}

FCos::FCos()
{
#ifdef _DEBUG
    cout << "FCos: Creating FCos\n";
#endif // _DEBUG
    parameters_number = 3;
    /*
        In default:
            a = 1
            b = 1
            c = 1
    */
    parameters.push_back(1);
    parameters.push_back(1);
    parameters.push_back(1);
}

FCos::~FCos() {
#ifdef _DEBUG
    cout << "FCos: Destroying FCos\n";
#endif // _DEBUG
}

bool FCos::checkParameters(vector<double> new_parameters) {

#ifdef _DEBUG
    cout << "FCos: Checking parameters\n";
    for (double new_parameter : new_parameters)
    {
        cout << new_parameter << " ";
    }
    cout << "\n";
#endif // _DEBUG
    //Check if parameters are good

    if (new_parameters.size() != parameters_number)
        return false;

    if (new_parameters[0] == 0)
        return false;

    if (new_parameters[1] == 0)
        return false;

    if (new_parameters[2] == 0)
        return false;

    return true;
}

double FCos::calculateValue(double t) {
#ifdef _DEBUG
    cout << "FCos: Count value of t\n";
    cout << "   Cos(t) = a*cos(b*t)^c\n";
#endif // _DEBUG

    double& a = parameters[0];
    double& b = parameters[1];
    double& c = parameters[2];

    double result;

    result = a * pow(cos(b * t), c);

#ifdef _DEBUG
    cout << "   a: " << a << " b: " << b << " c: " << c << "\n";
    cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}


void FCos::showFunction(bool not_first) {

    double& a = parameters[0];
    double& b = parameters[1];
    double& c = parameters[2];

    if (not_first && a > 0)
        cout << "+ ";
    else if (not_first && a < 0)
        cout << "- ";
    else if (!not_first && a < 0)
        cout << "-";
    if (a == 1) {}
    else
        cout << fabs(a);
    cout << "cos(";
    if (b == 1) {}
    else if (b == -1)
        cout << "-*";
    else
        cout << b << "*";
    cout << "t)";
    if (c == 1) {}
    else if (c < 0)
        cout << "^(" << c << ")";
    else
        cout << "^" << c;
    cout << " ";
}


FSin::FSin() {
#ifdef _DEBUG
    cout << "FSin: Creating FSin\n";
#endif // _DEBUG
    parameters_number = 3;
    /*
        In default:
            a = 1
            b = 1
            c = 1
    */
    parameters.push_back(1);
    parameters.push_back(1);
    parameters.push_back(1);
}

FSin::~FSin() {
#ifdef _DEBUG
    cout << "FSin: Destroying FSin\n";
#endif // _DEBUG
}

bool FSin::checkParameters(vector<double> new_parameters) {

#ifdef _DEBUG
    cout << "FSin: Checking parameters\n";
    for (int i = 0; i < new_parameters.size(); i++) {
        cout << new_parameters[i] << " ";
    }
    cout << "\n";
#endif // _DEBUG
    //Check if parameters are good

    if (new_parameters.size() != parameters_number)
        return false;

    if (new_parameters[0] == 0)
        return false;

    if (new_parameters[1] == 0)
        return false;

    if (new_parameters[2] == 0)
        return false;

    return true;
}

double FSin::calculateValue(double t) {
#ifdef _DEBUG
    cout << "FSin: Count value of t\n";
    cout << "   Sin(t) = a*sin(b*t)^c\n";
#endif // _DEBUG

    double& a = parameters[0];
    double& b = parameters[1];
    double& c = parameters[2];

    double result;

    result = a * pow(sin(b * t), c);

#ifdef _DEBUG
    cout << "   a: " << a << " b: " << b << " c: " << c << "\n";
    cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}

void FSin::showFunction(const bool not_first) {

    double& a = parameters[0];
    double& b = parameters[1];
    double& c = parameters[2];

    if (not_first && a > 0)
        cout << "+ ";
    else if (not_first && a < 0)
        cout << "- ";
    else if (!not_first && a < 0)
        cout << "-";
    if (a == 1) {}
    else
        cout << fabs(a);
    cout << "sin(";
    if (b == 1) {}
    else if (b == -1)
        cout << "-*";
    else
        cout << b << "*";
    cout << "t)";
    if (c == 1) {}
    else if (c < 0)
        cout << "^(" << c << ")";
    else
        cout << "^" << c;
    cout << " ";
}

FMonomial::FMonomial() {
#ifdef _DEBUG
    cout << "FMonomial: Creating FMonomial\n";
#endif // _DEBUG
    parameters_number = 3;
    /*
        In default:
            a = 1
            b = 1
            c = 1
    */
    parameters.push_back(1);
    parameters.push_back(1);
    parameters.push_back(1);
}

FMonomial::~FMonomial() {
#ifdef _DEBUG
    cout << "FMonomial: Destroying FMonomial\n";
#endif // _DEBUG
}

bool FMonomial::checkParameters(vector<double> new_parameters) {

#ifdef _DEBUG
    cout << "FMonomial: Checking parameters\n";
    for (int i = 0; i < new_parameters.size(); i++) {
        cout << new_parameters[i] << " ";
    }
    cout << "\n";
#endif // _DEBUG
    //Check if parameters are good

    if (new_parameters.size() != parameters_number)
        return false;

    if (new_parameters[0] == 0)
        return false;

    if (new_parameters[2] == 0)
        return false;

    return true;
}

double FMonomial::calculateValue(double t) {
#ifdef _DEBUG
    cout << "FMonomial: Count value of t\n";
    cout << "   Monomial(t) = a*(b+t)^c\n";
#endif // _DEBUG

    double& a = parameters[0];
    double& b = parameters[1];
    double& c = parameters[2];

    double result;

    result = a * pow((b + t), c);

#ifdef _DEBUG
    cout << "   a: " << a << " b: " << b << " c: " << c << "\n";
    cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}

void FMonomial::showFunction(const bool not_first) {

    double& a = parameters[0];
    double& b = parameters[1];
    double& c = parameters[2];

    if (not_first && a > 0)
        cout << "+ ";
    else if (not_first && a < 0)
        cout << "- ";
    else if (!not_first && a < 0)
        cout << "-";
    if (a == 1) {}
    else
        cout << fabs(a);
    cout << "sin(";
    if (b == 1) {}
    else if (b == -1)
        cout << "-*";
    else
        cout << b << "*";
    cout << "t)";
    if (c == 1) {}
    else if (c < 0)
        cout << "^(" << c << ")";
    else
        cout << "^" << c;
    cout << " ";
}

FConstant::FConstant() {
#ifdef _DEBUG
    cout << "FConstant: Creating FConstant\n";
#endif // _DEBUG
    parameters_number = 1;
    /*
        In default:
            a = 1
    */
    parameters.push_back(1);
}

FConstant::~FConstant() {
#ifdef _DEBUG
    cout << "FConstant: Destroying FConstant\n";
#endif // _DEBUG
}

bool FConstant::checkParameters(vector<double> new_parameters) {

#ifdef _DEBUG
    cout << "FConstant: Checking parameters\n";
    for (int i = 0; i < new_parameters.size(); i++) {
        cout << new_parameters[i] << " ";
    }
    cout << "\n";
#endif // _DEBUG
    //Check if parameters are good

    if (new_parameters.size() != parameters_number)
        return false;

    if (new_parameters[0] == 0)
        return false;

    return true;
}

double FConstant::calculateValue(double t) {
#ifdef _DEBUG
    cout << "FConstant: Count value of t\n";
    cout << "   Constant(t) = a\n";
#endif // _DEBUG

    double& a = parameters[0];

    double result;

    result = a;

#ifdef _DEBUG
    cout << "   a: " << a << "\n";
    cout << "   result: " << result << "\n";
#endif // _DEBUG

    return result;
}

void FConstant::showFunction(const bool not_first) {

    double& a = parameters[0];
    double& b = parameters[1];
    double& c = parameters[2];

    if (not_first && a > 0)
        cout << "+ ";
    else if (not_first && a < 0)
        cout << "- ";
    else if (!not_first && a < 0)
        cout << "-";
    if (a == 1) {}
    else
        cout << fabs(a);
    cout << "sin(";
    if (b == 1) {}
    else if (b == -1)
        cout << "-*";
    else
        cout << b << "*";
    cout << "t)";
    if (c == 1) {}
    else if (c < 0)
        cout << "^(" << c << ")";
    else
        cout << "^" << c;
    cout << " ";
}