//Andrzej Kusiak

#include <iostream>
#include <vector>
#include "Functions.hpp"
#include "InputController.hpp"


using namespace std;


Equation::Equation() {
    #ifdef _DEBUG
        cout << "Creating Equation\n";
    #endif // _DEBUG
}

Equation::~Equation() {
    #ifdef _DEBUG
        cout << "Destroying Equation\n";
    #endif // _DEBUG
    for (auto& v : equation) {
       delete v;
    #ifdef _DEBUG
            cout << "Destroying trigonometric function\n";
    #endif // _DEBUG
    }
}


void Equation::operator += (int func_type) {
    Function* p = NULL;
    switch (func_type) {
    case 1:
        p = new FSin;
        equation.push_back(p);
#ifdef _DEBUG
        cout << "Adding FCos to Equation\n";
#endif // _DEBUG
        break;

    case 2:
        p = new FCos;
        equation.push_back(p);
#ifdef _DEBUG
        cout << "Adding FSin to Equation\n";
#endif // _DEBUG
        break;

    case 3:
        p = new FMonomial;
        equation.push_back(p);
#ifdef _DEBUG
        cout << "Adding FPolynomial to Equation\n";
#endif // _DEBUG
        break;

    case 4:
        p = new FConstant;
        equation.push_back(p);
#ifdef _DEBUG
        cout << "Adding FConstant to Equation\n";
#endif // _DEBUG
        break;
    }
    double a, b, c;
    vector<double> parameters;
    bool correct_input;
    if (func_type >= 1 && func_type <= 3) {
        do {
            parameters = { 0, 0, 0 };
            correct_input = true;
            cout << "Parameters of this element: ";
            cin >> a >> b >> c;
            if (cin.fail()) {
                cout << "Invalid parameters\n" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                correct_input = false;
            }
            else {
                parameters.at(0) = a;
                parameters.at(1) = b;
                parameters.at(2) = c;
                if (!p->checkParameters(parameters)) {
                    cout << "Parameters can't be 0\n" << endl;
                    correct_input = false;
                }
            }
        } while (!correct_input);
    }
    else if (func_type == 4) {
        do {
            parameters = { 0 };
            correct_input = true;
            cout << "Value of your constant: ";
            cin >> a;
            if (cin.fail()) {
                cout << "Invalid parameter\n" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                correct_input = false;
            }
            else {
                parameters.at(0) = a;
                if (!p->checkParameters(parameters)) {
                    cout << "Constant can't be equal to 0\n" << endl;
                    correct_input = false;
                }
            } 
        } while (!correct_input);
    }
    equation.back()->setParameters(parameters);
    cout << endl;
}


void Equation::setOperation(char c) {
    equation.back()->setOperation(c);
}


void Equation::printEquation() const {
    bool not_first = false;
    for (auto v : equation) {
        v->showFunction(not_first);
        not_first = true;
    }
    cout << endl;
}


const vector<Function*>& Equation::getEquation() {
    return equation;
}


InputController::InputController() {
    number_of_points = 1;
    left_border = -1;
    right_border = 1;
#ifdef _DEBUG
    cout << "Creating InputController\n";
#endif // _DEBUG
}

InputController::~InputController() {
#ifdef _DEBUG
    cout << "Destroying InputController\n";
#endif // _DEBUG
}


void InputController::addToEquation(Equation* Eq) {
    int n, fun_type;
    bool correct_input;
    char operation = '+';
    do {
        cout << "How many element do you want to add to your equation: ";
        cin >> n;
        if (cin.fail()) {
            cout << "Number of elements must be an positive integer\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (n <= 0)
            cout << "Number of elements can't be a non-positive number\n" << endl;
    } while (cin.fail() || n <= 0);
    cout << endl;

    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            correct_input = true;
            do {
                cout << "Which operation do you want to use? ";
                cin >> operation;
                if (cin.fail()) {
                    cout << "Invalid input\nChoose between: \"+\", \"-\", \"*\", \"/\"\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    correct_input = false;
                }
                else if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
                    cout << "Operations allowed: \"+\", \"-\", \"*\", \"/\"\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    correct_input = false;
                }
            } while (!correct_input);
            cout << endl;
        }
        do {
            correct_input = true;
            cout << "Which function do you want to use?\n";
            cout << "1. a*sin(b*t)*c    2. a*cos(b*t)*c    3. a*(b+t)*c    4. Constant" << endl;
            cout << "Your choice: ";
            cin >> fun_type;
            if (cin.fail()) {
                cout << "Invalid input\n";
                cout << "Choose between 1, 2, 3 and 4\n" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                correct_input = false;
            }
            else if (fun_type < 1 || fun_type > 4) {
                cout << "Choose between given funtions\n" << endl;
                correct_input = false;
            }
        } while (!correct_input);
        cout << endl;
        *Eq += fun_type;
        Eq->setOperation(operation);
    }
}


void InputController::getInput() {
    do {
        cout << "How many points do you want to draw: ";
        cin >> number_of_points;
        if (cin.fail() || number_of_points <= 0) {
            cout << "Number of points must be an positive integer\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (cin.fail() || number_of_points <= 0);
    bool correct_input;
    do {
        correct_input = true;
        cout << endl << "Field of your equation: ";
        cin >> left_border >> right_border;
        if (cin.fail()) {
            cout << "Invalid input" << endl << "Give <x, y> as space seperated values" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            correct_input = false;
        }
        else if (left_border >= right_border) {
            cout << "Left border value can't be bigger than right or same as right" << endl;
            correct_input = false;
        }

    } while (!correct_input);
    cout << endl;

    // X parameter
    cout << "X equation components" << endl;
    addToEquation(&X);

    // Y parameter
    cout << endl << "Y equation components" << endl;
    addToEquation(&Y);

    cout << endl << "Your equations are: " << endl;
    printEquations();
}


void InputController::printEquations() const {
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


Equation& InputController::getXEquation() {
    return X;
}


Equation& InputController::getYEquation() {
    return Y;
}