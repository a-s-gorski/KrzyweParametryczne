#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

class Complex {
private:
	const double EPS = 1e-9;
	double re = 0;
	double im = 0;
	double phi = 0;
	double r = 0;

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

	double getPhi() { return phi; }
	double getAbsoluteValue() { return r; }
	double getRe() { return re; }
	double getIm() { return im; }

	std::string show(Complex::FORM ver);
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