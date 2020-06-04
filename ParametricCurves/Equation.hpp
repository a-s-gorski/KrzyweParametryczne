// Andrzej Kusiak
#ifndef EQUATION_H
#define EQUATION_H
#include <iostream>
#include <vector>
#include "Functions.hpp"


template <typename T>
class Equation {
    std::vector<T*> equation;
public:
    Equation();
    void operator += (T* func);
    const std::vector<T*>& getEquation();
    ~Equation();
    friend std::ostream& operator<<(std::ostream& os, Equation<T>& ob) {
        bool not_first = false;
        for (auto v : ob.equation) {
            v->showFunction(not_first);
            not_first = true;
        }
        os << endl;
        return os;
    }
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


template <typename T>
const vector<T*>& Equation<T>::getEquation() {
    return equation;
}