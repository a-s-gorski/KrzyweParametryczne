#include <iostream>
#include <vector>
#include <cmath>
#include "Functions.hpp"
#include "TestFunctions.hpp"

using namespace std;

void testFunctionsConstructor() {
    FCos func_1;
    FCos func_2 = func_1;
    FCos func_3(func_2);
}

bool testFunctionsCheckParameters() {
    bool assert = true;

    FSin func;

    cout << "Check parameters started: \n";

    //Correct parameters
    vector<double> test_1{ 1,2,3 };

    assert *= (true == func.checkParameters(test_1));

    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    //Wrong zero parameter
    vector<double> test_2{ 1,0,1 };

    assert *= (false == func.checkParameters(test_2));

    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    //Too less parameters
    vector<double> test_3{ 1,2 };

    assert *= (false == func.checkParameters(test_3));

    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    //Too much parameters
    vector<double> test_4{ 1,2,3,4 };

    assert *= (false == func.checkParameters(test_4));

    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    return assert;
}

bool testFunctionsCalculateValue() {
    bool assert = true;

    FCos func_1;
    FSin func_2;

    cout << "Calculate value started: \n";

    double test = 1;
    assert *= (cos(test) == func_1.calculateValue(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 0;
    assert *= (cos(test) == func_1.calculateValue(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 3.14;
    assert *= (cos(test) == func_1.calculateValue(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 1;
    assert *= (sin(test) == func_2.calculateValue(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 0;
    assert *= (sin(test) == func_2.calculateValue(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 3.14;
    assert *= (sin(test) == func_2.calculateValue(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    return assert;
}

void testFunctions() {
    cout << "Test Functions.\n\n";
    cout << "Check parameters: " << (testFunctionsCheckParameters() ? "Correct\n\n" : "Failed\n\n");
    cout << "Calculate value: " << (testFunctionsCalculateValue() ? "Correct\n\n" : "Failed\n\n");
}
