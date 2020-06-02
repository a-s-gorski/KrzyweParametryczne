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

	std::string show(Complex::FORM ver);

	friend std::istream& operator >> (std::istream& in, Complex& c)
	{
		in >> c.re;
		in >> c.im;
		return in;
	}

	Complex operator + (Complex const& c) {
		double RE = re + c.re;
		double IM = im + c.im;
		Complex res(RE, IM);
		return res;
	}

	Complex operator - (Complex const& c) {
		double RE = re - c.re;
		double IM = im - c.im;
		Complex res(RE, IM);
		return res;
	}

	Complex operator * (Complex const& c) {
		double RE = re * c.re - im * c.im;
		double IM = re * c.im + im * c.re;
		Complex res(RE, IM);
		return res;
	}

	Complex operator / (Complex const& c) {
		double RE = (re * c.re + im * c.im)/(re*re + im*im);
		double IM = (re * c.im - im * c.re)/(re*re + im*im);
		Complex res(RE, IM);
		return res;
	}

	void operator = (const Complex& c) {
		re = c.re;
		im = c.im;
		phi = c.phi;
		r = c.r;
	}

	Complex& operator+=(const Complex& c) {

		re += c.re;
		im += c.im;
		calculatePhi();
		calculateR();
		return *this;
	}

	Complex& operator-=(const Complex& c) {

		re -= c.re;
		im -= c.im;
		calculatePhi();
		calculateR();
		return *this;
	}

	Complex& operator*=(const Complex& c) {

		double temp_re = re;

		re = re * c.re - im * c.im;
		im = temp_re * c.im + im * c.re;

		calculatePhi();
		calculateR();
		return *this;
	}

	Complex& operator/=(const Complex& c) {

		double temp_re = re;

		re = (re * c.re + im * c.im) / (re * re + im * im);
		im = (re * c.im - im * c.re) / (re * re + im * im);

		calculatePhi();
		calculateR();
		return *this;
	}
};
