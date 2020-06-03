
//£ukasz Bondaruk

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

class Complex {
private:
	// Eps to compare doubles
	const double EPS = 1e-9;
	// Real part of number
	double re = 0;
	// Imaginary part of number
	double im = 0;
	// Phi of number in trigonometric or exponential form
	double phi = 0;
	// R of number in trigonometric or exponential form
	double r = 0;

	// Calculate proper value and set it 
	void calculatePhi();
	void calculateR();

public:
	enum FORM {
		CANONICAL,
		TRIGONOMETRIC,
		EXPONENTIAL
	};

	Complex(double x = 0, double y = 0);
	Complex(const Complex& c);
	~Complex();

	// Getters
	double getPhi() { return phi; }
	double getAbsoluteValue() { return r; }
	double getRe() { return re; }
	double getIm() { return im; }

	// Print function in proper form
	std::string show(Complex::FORM ver);

	// Set function to it conjugation
	Complex reflect();

	friend std::istream& operator >> (std::istream& in, Complex& c)
	{
		in >> c.re;
		in >> c.im;
		return in;
	}

	friend std::ofstream& operator << (std::ofstream& out, Complex& c)
	{
		//out << 
		return out;
	}

	//Arithmetic operators with Complex and double

	Complex operator + (Complex const& c);
	Complex operator + (double re);

	Complex operator - (Complex const& c);
	Complex operator - (double re);

	Complex operator * (Complex const& c);
	Complex operator * (double re);

	Complex operator / (Complex const& c);
	Complex operator / (double re);

	void operator = (const Complex& c);
	void operator = (const double& c);

	Complex& operator+=(const Complex& c);
	Complex& operator+=(const double& c);

	Complex& operator-=(const Complex& c);
	Complex& operator-=(const double& c);

	Complex& operator*=(const Complex& c);
	Complex& operator*=(const double& c);

	Complex& operator/=(const Complex& c);
	Complex& operator/=(const double& c);
};

#endif