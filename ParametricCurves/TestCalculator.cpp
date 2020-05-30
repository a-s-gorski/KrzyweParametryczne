//Łukasz Bondaruk

#include <iostream>
#include <vector>
#include <cmath>
#include "Functions.hpp"
#include "Calculator.hpp"
#include "TestCalculator.hpp"

using namespace std;

bool testCalculatorCalculateValue() {

    Calculator cal;

    vector<Function<double>*> x_function;
    vector<Function<double>*> y_function;

    FCos<double>* cos_1 = new FCos<double>;
    FSin<double>* sin_1 = new FSin<double>;

    x_function.push_back(cos_1);
    y_function.push_back(sin_1);

    bool assert = true;

    cout << "Calculate value started: \n";

    pair<double, double> test = make_pair(cos(1), sin(1));
   // Co to miao by *= ?
    assert &= test == cal.calculateValue(&x_function, &y_function, 1);
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = make_pair(cos(0), sin(0));
    assert &= test == cal.calculateValue(&x_function, &y_function, 0);
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = make_pair(cos(3.14), sin(3.14));
    assert &= test == cal.calculateValue(&x_function, &y_function, 3.14);
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = make_pair(cos(-1), sin(-1));
    assert &= test == cal.calculateValue(&x_function, &y_function, -1);
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    return assert;
}

bool testCalculatorCalculateSerie() {
    Calculator cal;

    vector<Function<double>*> x_function;
    vector<Function<double>*> y_function;

    FCos<double>* cos_1 = new FCos<double>;
    FSin<double>* sin_1 = new FSin<double>;

    x_function.push_back(cos_1);
    y_function.push_back(sin_1);

    bool assert = true;

    cout << "Calculate serie started: \n";

    vector<pair<double, double> > points;

    points = cal.calculateSerie(&x_function, &y_function, 1, 1, 1);
    assert &= (points[0].first == cos(1) && points[0].second == sin(1));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    points = cal.calculateSerie(&x_function, &y_function, 1, 2, 2);
    assert &= (points[0].first == cos(2) && points[0].second == sin(2));
    assert &= (points[1].first == cos(1) && points[1].second == sin(1));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    return assert;

}

void testCalculator() {
    cout << "Test Calculator.\n\n";
    cout << "Calculate value : " << (testCalculatorCalculateValue() ? "Correct\n\n" : "Failed\n\n");
    cout << "Calculate serie: " << (testCalculatorCalculateSerie() ? "Correct\n\n" : "Failed\n\n");
}

