#include <iostream>
#include <vector>
#include <cmath>
#include "functions.hpp"
#include "test_functions.hpp"

using namespace std;

void test_functions_constructor(){
    FCos func_1;
    FCos func_2 = func_1;
    FCos func_3(func_2);
}

bool test_functions_check_parameters(){
    bool assert = true;

    FSin func;

    cout << "Check parameters started: \n";

    //Correct parameters
    vector<double> test_1{1,2,3};

    assert *= (true==func.check_parameters(test_1));

    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    //Wrong zero parameter
    vector<double> test_2{1,0,1};

    assert *= (false==func.check_parameters(test_2));

    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    //Too less parameters
    vector<double> test_3{1,2};

    assert *= (false==func.check_parameters(test_3));

    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    //Too much parameters
    vector<double> test_4{1,2,3,4};

    assert *= (false==func.check_parameters(test_4));

    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    return assert;
}

bool test_functions_calculate_value(){
    bool assert = true;

    FCos func_1;
    FSin func_2;

    cout << "Calculate value started: \n";

    double test = 1;
    assert *= (cos(test)==func_1.calculate_value(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 0;
    assert *= (cos(test)==func_1.calculate_value(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 3.14;
    assert *= (cos(test)==func_1.calculate_value(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 1;
    assert *= (sin(test)==func_2.calculate_value(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 0;
    assert *= (sin(test)==func_2.calculate_value(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    test = 3.14;
    assert *= (sin(test)==func_2.calculate_value(test));
    cout << "   assert: " << (assert ? "Correct\n" : "Failed\n");

    return assert;
}

void test_functions(){
    cout << "Test Functions.\n\n";
    cout << "Check parameters: " << (test_functions_check_parameters()? "Correct\n\n" : "Failed\n\n");
    cout << "Calculate value: " << (test_functions_calculate_value()? "Correct\n\n" : "Failed\n\n");
}
