#include <iostream>
#include <string>
#include <cmath>
#include "ComplexNumber.hpp"

using namespace std;

Complex::Complex(double x, double y) : re(x), im(y) {

}

Complex::Complex(const Complex& c) {
	this->re = c.re;
	this->im = c.im;
	this->phi = c.phi;
	this->r = c.r;
}

Complex::~Complex() {

}

void Complex::calculatePhi() {
	double result = atan2(this->im, this->re);
}

void Complex::calculateR() {
	double result = sqrt(pow(this->re, 2) + pow(this->im, 2));
	this->r = result;
}

string Complex::show(FORM ver) {

	string c;
	switch (ver) {
	case(TRIGONOMETRIC):
		if (abs(r) > EPS) {
			c = to_string(r) + "( cos(" + to_string(phi) + ") + sin(" + to_string(phi) + ") )";
		}
		else {
			c = "0";
		}
		break;
	case(EXPONENTIAL):
		if (abs(r) > EPS) {
			if (abs(phi) > EPS) {
				c = to_string(r) + "e^(" + to_string(phi) + "i)";
			}
			else {
				c = to_string(r);
			}
		}
		else {
			c = "0";
		}
		break;
	default:
		//Canonical
		if (abs(re) > EPS && abs(im) > EPS) {
			c = to_string(re) + " " + to_string(im) + "i";
		}
		else if (abs(re) > EPS) {
			c = to_string(re);
		}
		else if (abs(im) > EPS) {
			c = to_string(im) + "i";
		}
		else {
			c = "0";
		}
		break;
	}
	return c;
}