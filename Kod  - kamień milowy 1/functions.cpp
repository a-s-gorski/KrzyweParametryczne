#include<iostream>
#include<cmath>
#include "functions.hpp"

using namespace std;

Function::~Function(){
    #ifdef _DEBUG
        cout << "Function: Destroying Function\n";
    #endif // _DEBUG
}

void Function::set_parameters(double new_parameters[]){
    #ifdef _DEBUG
        cout << "Function: New parameters\n";
        for(int i =0; i<parameters_number; i++){
            cout << "   " << i << " : " << new_parameters[i] << "\n";
        }
    #endif // _DEBUG
    parameters = new_parameters;
}

FCos::FCos(){
    #ifdef _DEBUG
        cout << "FCos: Creating FCos\n";
    #endif // _DEBUG
    parameters_number = 3;
    parameters = new double[parameters_number];
    /*
        In default:
            a = 1
            b = 1
            c = 1
    */
    parameters[0] = 1;
    parameters[1] = 1;
    parameters[2] = 1;
}

FCos::~FCos(){
    #ifdef _DEBUG
        cout << "FCos: Destroying FCos\n";
    #endif // _DEBUG
}

bool FCos::check_parameters(double new_parameters[]){

    int new_parameters_number = sizeof(new_parameters)/sizeof(double);
    bool is_correct = true;

    #ifdef _DEBUG
        cout << "FCos: Checking parameters\n";
        for(int i=0; i<new_parameters_number; i++){
            cout << new_parameters[i] << " ";
        }
        cout << "\n";
    #endif // _DEBUG
    //Check if parameters are good

    if (new_parameters_number!=parameters_number)
        is_correct = false;

    if (new_parameters[0]==0)
        is_correct = false;

    if (new_parameters[1]==0)
        is_correct = false;

    if (new_parameters[2]==0)
        is_correct = false;

    return is_correct;
}

double FCos::calculate_value(double t){
    #ifdef _DEBUG
        cout<< "FCos: Count value of t\n";
        cout << "   Cos(t) = a*cos(b*t)^c\n";
    #endif // _DEBUG

    double & a = parameters[0];
    double & b = parameters[1];
    double & c = parameters[2];

    double result;

    result = pow(a*cos(b*t),c);

    #ifdef _DEBUG
        cout << "   a: " << a << " b: " << b << " c: " << c << "\n";
        cout << "   result: " << result << "\n";
    #endif // _DEBUG

    return result;
}

FSin::FSin(){
    #ifdef _DEBUG
        cout << "FSin: Creating FSin\n";
    #endif // _DEBUG
    parameters_number = 3;
    parameters = new double[parameters_number];
    /*
        In default:
            a = 1
            b = 1
            c = 1
    */
    parameters[0] = 1;
    parameters[1] = 1;
    parameters[2] = 1;
}

FSin::~FSin(){
    #ifdef _DEBUG
        cout << "FSin: Destroying FSin\n";
    #endif // _DEBUG
}

bool FSin::check_parameters(double new_parameters[]){

    int new_parameters_number = sizeof(new_parameters)/sizeof(double);
    bool is_correct = true;

    #ifdef _DEBUG
        cout << "FSin: Checking parameters\n";
        for(int i=0; i<new_parameters_number; i++){
            cout << new_parameters[i] << " ";
        }
        cout << "\n";
    #endif // _DEBUG
    //Check if parameters are good

    if (new_parameters_number!=parameters_number)
        is_correct = false;

    if (new_parameters[0]==0)
        is_correct = false;

    if (new_parameters[1]==0)
        is_correct = false;

    if (new_parameters[2]==0)
        is_correct = false;

    return is_correct;
}

double FSin::calculate_value(double t){
    #ifdef _DEBUG
        cout<< "FSin: Count value of t\n";
        cout << "   Sin(t) = a*sin(b*t)^c\n";
    #endif // _DEBUG

    double & a = parameters[0];
    double & b = parameters[1];
    double & c = parameters[2];

    double result;

    result = pow(a*sin(b*t),c);

    #ifdef _DEBUG
        cout << "   a: " << a << " b: " << b << " c: " << c << "\n";
        cout << "   result: " << result << "\n";
    #endif // _DEBUG

    return result;
}

