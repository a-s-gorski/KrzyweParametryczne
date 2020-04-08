#include <iostream>
#include <vector>
#include "functions.hpp"
#include "InputController.hpp"


using namespace std;

InputController::InputController() {
    #ifdef _DEBUG
        cout << "Creating InputController\n";
    #endif // _DEBUG
}

InputController::~InputController() {
    #ifdef _DEBUG
        cout << "Destroying InputController\n";
    #endif // _DEBUG
}

Equation::Equation() {
    #ifdef _DEBUG
        cout << "Creating Equation\n";
    #endif // _DEBUG
}

Equation::~Equation() {
    #ifdef _DEBUG
        cout << "Destroying Equation\n";
    #endif // _DEBUG
}


void InputController::getInput() {
    cout << "How many points do you want to draw: ";
    cin>>number_of_points;
    cout << endl << "Field of your equation: ";
    cin>>left_border>>right_border;
    cout << endl;
    
    // X parameter
    cout << "X equation components" << endl;
    int n;
    cout << "How many element do you want to add to your X equation: ";
    cin>>n;
    cout << endl;
    string s;
    double a, b, c;
    for(int i=0; i<n; ++i) {
        cout << "Cos or sin function? [sin/cos] ";
        cin>>s;
        cout << endl << "Parameters of this element: ";
        cin>>a>>b>>c;
        cout << endl;
        vector<double> parameters{a, b, c};
        if(s == "sin") {
            static FSin temp;
            X.equation.push_back(&temp);
            X.equation[i]->check_parameters(parameters);
            X.equation[i]->set_parameters(parameters);
        }
        if(s == "cos") {
            static FCos temp;
            X.equation.push_back(&temp);
            X.equation[i]->check_parameters(parameters);
            X.equation[i]->set_parameters(parameters);
        }
    }


    // Y parameter
    cout << "Y equation components" << endl;
    cout << "How many element do you want to add to your Y equation: ";
    cin>>n;
    for(int i=0; i<n; ++i) {
        cout << "Cos or sin function? [sin/cos] ";
        cin>>s;
        cout << endl << "Parameters of this element: ";
        cin>>a>>b>>c;
        cout << endl;
        vector<double> parameters{a, b, c};
        if(s == "sin") {
            static FSin temp;
            Y.equation.push_back(&temp);
            Y.equation[i]->check_parameters(parameters);
            Y.equation[i]->set_parameters(parameters);
        }
        if(s == "cos") {
            static FCos temp;
            Y.equation.push_back(&temp);
            Y.equation[i]->check_parameters(parameters);
            Y.equation[i]->set_parameters(parameters);
        }
    }
}

void FCos::showFunction() {
    if(parameters[0] > 0)
        cout << parameters[0] << "cos(" << parameters[1] << "*t)^" << parameters[2] << " ";
}

void FSin::showFunction() {
    cout << parameters[0] << "sin(" << parameters[1] << "*t)^" << parameters[2] << " ";
}

void Equation::printEquation() {
    for(auto v : equation) {
        v->showFunction();
    }
    cout << endl;
}

void InputController::printEquations() {
    cout << "X(t) = ";
    X.printEquation();
    cout << "Y(t) = ";
    Y.printEquation();
}


