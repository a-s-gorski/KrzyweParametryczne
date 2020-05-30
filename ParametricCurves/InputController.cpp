//Andrzej Kusiak

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Functions.hpp"
#include "InputController.hpp"
#include "Functions.cpp"


using namespace std;


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


void InputController::getFieldOfPointsToDraw() {
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
}


Function<double>* InputController::createFunction (int iterator) {
    char operation = '+';
    int fun_type;
    bool correct_input;
    Function<double>* p = NULL;

    if (iterator != 0) {
        do {
            correct_input = true;
            cout << "Which operation do you want to use?\nType: \"+\", \"-\", \"*\", \"/\": ";
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

    switch (fun_type) {
    case 1:
        p = new FSin<double>;
#ifdef _DEBUG
        cout << "Creating FSin\n";
#endif // _DEBUG
        break;

    case 2:
        p = new FCos<double>;
#ifdef _DEBUG
        cout << "Creating FCos\n";
#endif // _DEBUG
        break;

    case 3:
        p = new FMonomial<double>;
#ifdef _DEBUG
        cout << "Creating FPolynomial\n";
#endif // _DEBUG
        break;

    case 4:
        p = new FConstant<double>;
#ifdef _DEBUG
        cout << "Creating FConstant\n";
#endif // _DEBUG
        break;
    }

    double a, b, c;
    vector<double> parameters;
    if (fun_type >= 1 && fun_type <= 3) {
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
    else if (fun_type == 4) {
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
    cout << endl;
    
    p->setParameters(parameters);
    p->setOperation(operation);
    return p;

}


void InputController::addToEquation(Equation<Function<double>>* Eq) {
    int n;
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
        Function<double>* newFunction = createFunction(i);
        *Eq += newFunction;
    }
}


void InputController::getInput() {
    getFieldOfPointsToDraw();

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


Equation<Function<double>>& InputController::getXEquation() {
    return X;
}


Equation<Function<double>>& InputController::getYEquation() {
    return Y;
}


CommandLineInput::CommandLineInput() {
#ifdef _DEBUG
    cout << "Creating CommandLineInput\n";
#endif // _DEBUG
}


CommandLineInput::~CommandLineInput() {
#ifdef _DEBUG
    cout << "Destroying CommandLineInput\n";
#endif // _DEBUG
}


Function<double>* CommandLineInput::addToEquation(Equation<Function<double>>* Eq, char operation, double a) {
    Function<double>* p = new FConstant<double>;
#ifdef _DEBUG
    cout << "Creating FConstant\n";
#endif // _DEBUG
    vector<double> parameter{ a };
    p->setParameters(parameter);
    p->setOperation(operation);

    return p;
}


Function<double>* CommandLineInput::addToEquation(Equation<Function<double>>* Eq, char operation, int function, double a, double b, double c) {
    Function<double>* p;
    switch (function) {
    case 1:
        p = new FSin<double>;
#ifdef _DEBUG
        cout << "Creating FSin\n";
#endif // _DEBUG
        break;

    case 2:
        p = new FCos<double>;
#ifdef _DEBUG
        cout << "Creating FCos\n";
#endif // _DEBUG
        break;

    case 3:
        p = new FMonomial<double>;
#ifdef _DEBUG
        cout << "Creating FPolynomial\n";
#endif // _DEBUG
        break;
    }

    vector<double> parameters{ a, b, c };
    p->setParameters(parameters);
    p->setOperation(operation);

    return p;
}


void CommandLineInput::getInput(string filename) {
    ifstream f(filename);

    if (!f.is_open()) {
        cout << "Couldn't open a file" << endl;
        exit(1);
    }

    f >> number_of_points;
    f >> left_border;
    f >> right_border;

    int nelements;

    char operation = '+';
    double a, b, c;
    int func;
    Function<double>* ptr = NULL;
    for (int j = 0; j < 2; j++) {
        f >> nelements;
        for (int i = 0; i < nelements; i++) {
            if (i != 0)
                f >> operation;
            f >> func;
            if (func >= 1 && func <= 3) {
                f >> a >> b >> c;
                if (j == 0)
                    ptr = addToEquation(&X, operation, func, a, b, c);
                else if (j == 1)
                    ptr = addToEquation(&Y, operation, func, a, b, c);
            }
            else if (func == 4) {
                f >> a;
                if (j == 0)
                    ptr = addToEquation(&X, operation, a);
                else if (j == 1)
                    ptr = addToEquation(&Y, operation, a);
            }
            if (j == 0) {
                X += ptr;
            }
            else if (j == 1) {
                Y += ptr;
            }
        }
    }

    f.close();

    printEquations();
}