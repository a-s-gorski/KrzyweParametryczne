
//£ukasz Bondaruk

#include <iostream>
#include <string>
#include <cmath>
#include "ComplexNumber.hpp"

using namespace std;

Complex::Complex(double x, double y) : re(x), im(y) {
	calculateR();
	calculatePhi();
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
	double result = atan2(im, re);
	this->phi = result;
}

void Complex::calculateR() {
	double result = sqrt(re*re + im*im);
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

Complex Complex::reflect() {
	double RE = re;
	double IM = -im;
	Complex res(RE, IM);
	return res;
}

Complex Complex::operator + (Complex const& c) {
	double RE = re + c.re;
	double IM = im + c.im;
	Complex res(RE, IM);
	return res;
}

Complex Complex::operator + (double re) {
	double RE = this->re + re;
	double IM = im;
	Complex res(RE, IM);
	return res;
}

Complex Complex::operator - (Complex const& c) {
	double RE = re - c.re;
	double IM = im - c.im;
	Complex res(RE, IM);
	return res;
}

Complex Complex::operator - (double re) {
	double RE = this->re - re;
	double IM = im;
	Complex res(RE, IM);
	return res;
}

Complex Complex::operator * (Complex const& c) {
	double RE = re * c.re - im * c.im;
	double IM = re * c.im + im * c.re;
	Complex res(RE, IM);
	return res;
}

Complex Complex::operator * (double re) {
	double RE = this->re * re;
	double IM = this->im * re;
	Complex res(RE, IM);
	return res;
}

Complex Complex::operator / (Complex const& c) {
	double RE = double(re * c.re + im * c.im) / double(c.re * c.re + c.im * c.im);
	double IM = double(c.re * im - c.im * re) / double(c.re * c.re + c.im * c.im);
	Complex res(RE, IM);
	return res;
}

Complex Complex::operator / (double re) {
	double RE = this->re / re;
	double IM = this->im / re;
	Complex res(RE, IM);
	return res;
}

void Complex::operator = (const Complex& c) {
	re = c.re;
	im = c.im;
	phi = c.phi;
	r = c.r;
}

void Complex::operator = (const double& c) {
	re = c;
	im = 0;
	calculatePhi();
	calculateR();
}

Complex& Complex::operator+=(const Complex& c) {

	re += c.re;
	im += c.im;
	calculatePhi();
	calculateR();
	return *this;
}

Complex& Complex::operator-=(const Complex& c) {

	re -= c.re;
	im -= c.im;

	calculatePhi();
	calculateR();
	return *this;
}

Complex& Complex::operator*=(const Complex& c) {

	double temp_re = re;

	re = re * c.re - im * c.im;
	im = temp_re * c.im + im * c.re;

	calculatePhi();
	calculateR();
	return *this;
}

Complex& Complex::operator/=(const Complex& c) {

	double temp_re = re;

	re = double(re * c.re + im * c.im) / double(c.re * c.re + c.im * c.im);
	im = double(c.re * im - c.im * temp_re) / double(c.re * c.re + c.im * c.im);

	calculatePhi();
	calculateR();
	return *this;
}

Complex& Complex::operator+=(const double& c) {

	re += c;

	calculatePhi();
	calculateR();
	return *this;
}

Complex& Complex::operator-=(const double& c) {

	re -= c;

	calculatePhi();
	calculateR();
	return *this;
}

Complex& Complex::operator*=(const double& c) {

	re *= c;
	im *= c;

	calculatePhi();
	calculateR();
	return *this;
}

Complex& Complex::operator/=(const double& c) {

	re /= c;
	im /= c;

	calculatePhi();
	calculateR();
	return *this;
}