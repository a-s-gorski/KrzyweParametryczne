// Andrzej Kusiak
#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <iostream>
#include <vector>
#include "Functions.hpp"

template <typename T>
class Equation {
    std::vector<T*> equation;
public:
    Equation();
    // void printEquation() const;
    void operator += (T* func);
    const std::vector<T*>& getEquation();
    ~Equation();
    friend std::ostream& operator<<(std::ostream& os, Equation<T>& ob) {
        bool not_first = false;
        for (auto v : equation) {
            os << v->showFunction(os, not_first);
            not_first = true;
        }
        os << endl;
        return os;
    }
};


class InputController {
protected:
    int number_of_points;
    double left_border;
    double right_border;
    Equation<Function<double>> X;
    Equation<Function<double>> Y;
    virtual void setNumberOfPoints() = 0;
    virtual void setBorders() = 0;
    virtual void setXEquation() = 0;
    virtual void setYEquation() = 0;
    virtual Function<double>* createFunction(int iterator) = 0;

public:
    InputController();
    virtual void getInput();
    void printEquations() const;
    int getNumberOfPoints();
    double getLeftBorder();
    double getRightBorder();
    Equation<Function<double>>& getXEquation();
    Equation<Function<double>>& getYEquation();
    virtual ~InputController();
};


class CMDInput : public InputController {
private:
    void setNumberOfPoints();
    void setBorders();
    void setXEquation();
    void setYEquation();
    virtual Function<double>* createFunction(int iterator);

public:
    CMDInput();
    ~CMDInput();
    friend std::ostream& operator<<(std::ostream& os, CMDInput& ob);
};


class FileInput : public InputController {
    Function<double>* addToEquation(Equation<Function<double>>* Eq, char operation, int function, double a, double b, double c);
    Function<double>* addToEquation(Equation<Function<double>>* Eq, char operation, double a);
public:
    FileInput();
    void getInput(std::string filename);
    ~FileInput();
};
#endif


using namespace std;

template <typename T>
Equation<T>::Equation() {
#ifdef _DEBUG
    cout << "Creating Equation\n";
#endif // _DEBUG
}
template <typename T>
Equation<T>::~Equation() {
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

template <typename T>
void Equation<T>::operator += (T* func) {
    equation.push_back(func);
#ifdef _DEBUG
    cout << "Adding object to an Equation\n";
#endif // _DEBUG
}


/*template <typename T>
void Equation<T>::printEquation() const {
    bool not_first = false;
    for (auto v : equation) {
        v->showFunction(not_first);
        not_first = true;
    }
    cout << endl;
}*/

template <typename T>
const vector<T*>& Equation<T>::getEquation() {
    return equation;
}