#define CATCH_CONFIG_MAIN
#include <cmath>
#include <catch.hpp>        // Unit tests catch framework!!!
#include "InputController.hpp"
#include "Functions.hpp"

TEST_CASE("Equation test") {
    const double pi = 3.14159265358979323846;

    Equation p;

    p.addElementCos(1, 1, 1);
    p.addElementSin(1, 1, 1);
    p.addElementSin(2, 1, 1);
    p.addElementCos(1, 1, 2);
    p.addElementSin(1, 2, 1);

    const vector<Function*>& v = p.getEquation();

    SECTION("Getting correct Resault") {
        REQUIRE(v[0]->calculateValue(0) == 1);
        REQUIRE(v[1]->calculateValue(pi/2) == 1);
        REQUIRE(v[2]->calculateValue(pi/2) == 2);
        REQUIRE(round(v[3]->calculateValue(pi/4)*10)/10 == 0.5);
        REQUIRE(round(v[4]->calculateValue(pi/12)*10)/10 == 0.5);
    }
    SECTION("Checking if parameters are correct") {
        vector<double> p{0.242, -12.56, 1492388};
        vector<double> o{0, 0.24, 24};
        vector<double> l{7, 0, 5};
        vector<double> k{5, 0.21, 0};
        vector<double> m{pi, pi, pi};

        REQUIRE(v[0]->checkParameters(p) == true);
        REQUIRE(v[1]->checkParameters(o) == false);
        REQUIRE(v[2]->checkParameters(l) == false);
        REQUIRE(v[3]->checkParameters(k) == false);
        REQUIRE(v[4]->checkParameters(m) == true);
    }

}

void testInput(InputController d) {
    
    SECTION("Testing numerical values") {
        d.number_of_points = 1000;
        d.left_border = -2.256;
        d.right_border = 555.555;

        REQUIRE(d.getNumberOfPoints() == 1000);
        REQUIRE(d.getLeftBorder() == -2.256);
        REQUIRE(d.getRightBorder() == 555.555);
    }

    SECTION("Testing objects inside class") {
        const double pi = 3.14159265358979323846;

        d.X.addElementCos(4, 1, 2);
        d.X.addElementSin(-1, 4, 1);

        Equation& x = d.getXEquation();

        vector<Function*> v = x.getEquation();

        REQUIRE(round(v[0]->calculateValue(pi/6)) == 3.0);
        REQUIRE(round(v[1]->calculateValue(pi/24)*10)/10 == -0.5);
    }
}

TEST_CASE("InputController test") {
    InputController d;
    testInput(d);

}