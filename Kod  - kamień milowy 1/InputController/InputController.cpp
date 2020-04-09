#include <iostream>
#include <vector>
#include "../Funkcje/Functions.hpp"
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
    for(auto v : equation) {
        delete v;
        #ifdef _DEBUG
            cout << "Destroying trigonometric function\n";
        #endif // _DEBUG
    }
}


void InputController::addToEquation(Equation* Eq) {
    int n;
    string s;
    double a, b, c;
    bool correct_input;
    vector<double> parameters{0, 0, 0};
    do {
        cout << "How many element do you want to add to your equation: ";
        cin>>n;
        if(cin.fail()) {
            cout << "Number of elements must be an positive integer\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(n <= 0)
            cout << "Number of elements can't be a non-positive number\n" << endl;
    } while(cin.fail() || n <= 0);
    cout << endl;
    for(int i=0; i<n; ++i) {
        do {
            correct_input = true;
            cout << "Cos or sin function? [sin/cos] ";
            cin>>s;
            if(cin.fail()) {
                cout << "Choose between sin or cos function\n" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                correct_input = false;
            }
            else if(s != "sin" && s != "cos") {
                cout << "Choose between sin or cos function\n" << endl;
                correct_input = false;
            }
        } while(!correct_input);
        do {
            correct_input = true;
            cout << "Parameters of this element: ";
            cin>>a>>b>>c;
            if(cin.fail()) {
                cout << "Invalid parameters\n" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                correct_input = false;
            }
            else if(a == 0 || b == 0 || c == 0) {
                cout << "Parameters can't be 0\n" << endl;
                correct_input = false;
            }
        } while(!correct_input);
        cout << endl;
        #ifdef _DEBUG
            cout << a << " " << b << " " << c << endl << endl;
        #endif // _DEBUG
        parameters.at(0) = a;
        parameters.at(1) = b;
        parameters.at(2) = c;
        if(s == "sin") {
            Function* p = new FSin;
            Eq->equation.push_back(p);
            Eq->equation[i]->setParameters(parameters);
        }
        else if(s == "cos") {
            Function* p = new FCos;
            Eq->equation.push_back(p);
            Eq->equation[i]->setParameters(parameters);
        }
        else {
            cout << s << " is not defined" << endl;
            --i;
        }
    }
}


void InputController::getInput() {
    do {
        cout << "How many points do you want to draw: ";
        cin>>number_of_points;
        if(cin.fail() || number_of_points <= 0) {
            cout << "Number of points must be an positive integer\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while(cin.fail() || number_of_points <= 0);
    bool correct_input;
    do {
        correct_input = true;
        cout << endl << "Field of your equation: ";
        cin>>left_border>>right_border;
        if(cin.fail()) {
            cout << "Invalid input" << endl << "Give <x, y> as space seperated values" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            correct_input = false;
        }
        else if(left_border >= right_border) {
            cout << "Left border value can't be bigger than right or same as right" << endl;
            correct_input = false;
        }

    } while(!correct_input);
    cout << endl;
    
    // X parameter
    cout << "X equation components" << endl;
    addToEquation(&X);

    // Y parameter
    cout << "Y equation components" << endl;
    addToEquation(&Y);
}

void Equation::printEquation() {
    bool not_first = false;
    for(auto v : equation) {
        v->showFunction(not_first);
        not_first = true;
    }
    cout << endl;
}

void InputController::printEquations() {
    cout << "X(t) = ";
    X.printEquation();
    cout << "Y(t) = ";
    Y.printEquation();
}


int InputController::getNumberOfPoints() {
    return number_of_points;
}

double InputController::getLeftBorder() {
    return left_border;
}

double InputController::getRightBorder() {
    return right_border;
}

Equation* InputController::getXEquation() {
    return &X;
}

Equation* InputController::getYEquation() {
    return &Y;
}