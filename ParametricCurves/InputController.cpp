//Andrzej Kusiak

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Functions.hpp"
#include "Functions.cpp"
#include "InputController.hpp"
#include "MyException.hpp"



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


void InputController::getInput() {
    setNumberOfPoints();
    setBorders();
    setXEquation();
    setYEquation();
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


CMDInput::CMDInput() {
#ifdef _DEBUG
    cout << "Creating CMDInput\n";
#endif // _DEBUG
}


CMDInput::~CMDInput() {
#ifdef _DEBUG
    cout << "Destroying CMDInput\n";
#endif // _DEBUG
}


void CMDInput::setNumberOfPoints() {
    cin.exceptions(iostream::failbit);
    do {
        try {
            cout << "How many points do you want to draw: ";
            cin >> number_of_points;
            if (cin.peek() != '\n')
                throw notinteger;
        }
        catch (iostream::failure& iof) {
            cerr << "Invalid Input" << endl;
            cin.clear();                                // reset error flags
            cin.ignore(10000, '\n');    // clear buffer
        }
        catch (EnteredValueIsNotAnInteger& e) {
            cerr << e.what() <<  " You entered something after " << number_of_points << "." << endl;
            cin.clear();                                            // reset error flags
            cin.ignore(10000, '\n');    // clear buffer

            number_of_points = 0;      // reset num to its initial value
        }
        if (number_of_points < 0) {
            cout << "Number of points must be an positive integer\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (number_of_points <= 0);
}


void CMDInput::setBorders() {
    cin.exceptions(iostream::failbit);
    bool correct_input;
    do {
        correct_input = true;
        try {
            cout << endl << "Field of your equation: ";
            cin >> left_border;
        }
        catch (iostream::failure& iof) {
            cerr << "Invalid Input" << endl;
            correct_input = false;
        }

        try {
            cin >> right_border;
        }
        catch (iostream::failure& iof) {
            cerr << "Invalid Input" << endl;
            left_border = 0;
            correct_input = false;
        }
        if (left_border >= right_border || !correct_input) {
            cout << "Give <x, y> as space seperated values" << endl;
            cout << "Left border value can't be bigger than right or same as right" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            correct_input = false;
        }
    } while (!correct_input);
    cout << endl;
}

void CMDInput::setXEquation() {
    cin.exceptions(iostream::failbit);
    int n;
    do {
        try {
            cout << "How many element do you want to add to your X equation: ";
            cin >> n;
            if (cin.peek() != '\n')
                throw notinteger;
        }
        catch (iostream::failure& iof) {
            cerr << "Invalid Input " << endl;
            cin.clear();                                // reset error flags
            cin.ignore(10000, '\n');    // clear buffer
        }
        catch (EnteredValueIsNotAnInteger& e) {
            cerr << e.what() << " You entered something after " << n << "." << endl;
            cin.clear();                                            // reset error flags
            cin.ignore(10000, '\n');    // clear buffer

            n = 0;      // reset num to its initial value
        }
        if (n < 0) {
            cout << "Number of elements must be an positive integer\n" << endl;
            cin.clear();                                            // reset error flags
            cin.ignore(10000, '\n');    // clear buffer
        }
    } while (n <= 0);
    cout << endl;

    for (int i = 0; i < n; ++i) {
        Function<double>* newFunction = createFunction(i);
        X += newFunction;
    }
}


void CMDInput::setYEquation() {
    cin.exceptions(iostream::failbit);
    int n;
    do {
        try {
            cout << "How many element do you want to add to your Y equation: ";
            cin >> n;
            if (cin.peek() != '\n')
                throw notinteger;
        }
        catch (iostream::failure& iof) {
            cerr << "Invalid Input " << endl;
            cin.clear();                                // reset error flags
            cin.ignore(10000, '\n');    // clear buffer
        }
        catch (EnteredValueIsNotAnInteger& e) {
            cerr << e.what() << " You entered something after " << n << "." << endl;
            cin.clear();                                            // reset error flags
            cin.ignore(10000, '\n');    // clear buffer

            n = 0;      // reset num to its initial value
        }
        if (n < 0) {
            cout << "Number of elements must be an positive integer\n" << endl;
            cin.clear();                                            // reset error flags
            cin.ignore(10000, '\n');    // clear buffer
        }
    } while (n <= 0);
    cout << endl;

    for (int i = 0; i < n; ++i) {
        Function<double>* newFunction = createFunction(i);
        Y += newFunction;
    }
}


Function<double>* CMDInput::createFunction(int iterator) {
    cin.exceptions(iostream::failbit);
    char operation = '+';
    int fun_type;
    bool correct_input;
    Function<double>* p = NULL;

    if (iterator != 0) {
        do {
            correct_input = true;
            cout << "Which operation do you want to use?\nType: \"+\", \"-\", \"*\", \"/\": ";
            cin >> operation;
            
            if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
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
        cout << "1. a*sin(b*t)*c    2. a*cos(b*t)*c    3. a*(b+t)*c    4. Constant  5. a*(b)^t  6. log_a(t)" << endl;
        cout << "Your choice: ";
        try {
            cin >> fun_type;
        }
        catch (iostream::failure& iof) {
            cerr << "Invalid Input " << endl;
            cout << "Choose between 1, 2, 3, 4, 5 and 6\n" << endl;
            cin.clear();                                // reset error flags
            cin.ignore(10000, '\n');    // clear buffer
            correct_input = false;
        }
        if (fun_type < 1 || fun_type > 6) {
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
    case 5:
        p = new FExp<double>;
#ifdef _DEBUG
        cout << "Creating FExp\n";
#endif // _DEBUG
        break;
    case 6:
        p = new FLog<double>;
#ifdef _DEBUG
        cout << "Creating FLog\n";
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
            try {
                cin >> a >> b >> c;
            }
            catch (iostream::failure& iof) {
                cerr << "Invalid arameters\n" << endl;
                cin.clear();                                // reset error flags
                cin.ignore(10000, '\n');    // clear buffer
                correct_input = false;
            }
            if(correct_input) {
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
    else if (fun_type == 4 || fun_type == 6) {
        do {
            parameters = { 0 };
            correct_input = true;
            cout << "Parameters of this element: ";
            try {
                cin >> a;
            }
            catch (iostream::failure& iof) {
                cerr << "Invalid parameter\n" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                correct_input = false;
            }
            if(correct_input) {
                parameters.at(0) = a;
                if (!p->checkParameters(parameters)) {
                    cout << "This parametre is not allowed\n" << endl;
                    correct_input = false;
                }
            }
        } while (!correct_input);
    }
    else if (fun_type == 5) {
        do {
            correct_input = true;
            parameters = { 0, 0 };
            cout << "Parameters of this element: ";
            try {
                cin >> a >> b;
            }
            catch (iostream::failure& iof) {
                cerr << "Invalid arameters\n" << endl;
                cin.clear();                                // reset error flags
                cin.ignore(10000, '\n');    // clear buffer
                correct_input = false;
            }
            if (correct_input) {
                parameters.at(0) = a;
                parameters.at(1) = b;
                if (!p->checkParameters(parameters)) {
                    cout << "Parameters can't be 0\n" << endl;
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


ostream& operator<<(ostream& os, CMDInput& ob) {
    os << "X(t) = " << ob.X;
    os << "Y(t) = " << ob.Y;

    return os;
}


FileInput::FileInput(std::string s) : filename(s) {
    f.open(filename);

    if (!f.is_open()) {
        cout << "Couldn't open a file" << endl;
        exit(1);
    }
#ifdef _DEBUG
    cout << "Creating FileInput\n";
#endif // _DEBUG
}


FileInput::~FileInput() {
#ifdef _DEBUG
    cout << "Destroying FileInput\n";
#endif // _DEBUG
}


void FileInput::setNumberOfPoints() {
    f >> number_of_points;
}


void FileInput::setBorders() {
    f >> left_border;
    f >> right_border;
}


Function<double>* FileInput::createFunction(int iterator) {
    char operation = '+';
    double a, b, c;
    int func;
    Function<double>* p;

    if (iterator != 0)
        f >> operation;
    f >> func;
    if (func >= 1 && func <= 3) {
        f >> a >> b >> c;
    }
    else if (func == 4) {
        f >> a;
    }

    vector<double> parameters;

    switch (func) {
    case 1:
        p = new FSin<>;
        parameters.push_back(a);
        parameters.push_back(b);
        parameters.push_back(c);
#ifdef _DEBUG
        cout << "Creating FSin\n";
#endif // _DEBUG
        break;

    case 2:
        p = new FCos<>;
        parameters.push_back(a);
        parameters.push_back(b);
        parameters.push_back(c);
#ifdef _DEBUG
        cout << "Creating FCos\n";
#endif // _DEBUG
        break;

    case 3:
        p = new FMonomial<>;
        parameters.push_back(a);
        parameters.push_back(b);
        parameters.push_back(c);
#ifdef _DEBUG
        cout << "Creating FPolynomial\n";
#endif // _DEBUG
        break;
    case 4:
        p = new FConstant<>;
        parameters.push_back(a);
#ifdef _DEBUG
        cout << "Creating FConstant\n";
#endif // _DEBUG
    }

    p->setParameters(parameters);
    p->setOperation(operation);

    return p;
}

void FileInput::setXEquation() {
    Function<double>* p;
    int nelements;
    f >> nelements;
    for (int i = 0; i < nelements; i++) {
        p = createFunction(i);
        X += p;
    }
}


void FileInput::setYEquation() {
    Function<double>* p;
    int nelements;
    f >> nelements;
    for (int i = 0; i < nelements; i++) {
        p = createFunction(i);
        Y += p;
    }
}


void FileInput::getInput() {
    setNumberOfPoints();
    setBorders();
    setXEquation();
    setYEquation();

    f.close();
}


ostream& operator<<(ostream& os, FileInput& ob) {
    os << "X(t) = " << ob.X;
    os << "Y(t) = " << ob.Y;

    return os;
}