# Fields

## Re
    Real part of Compelx Number
    
## Im
    Imaginary part of Compelx Number

## Phi
    Phi of number in trigonometric or exponential form

## R
    R of number in trigonometric or exponential form


# Forms
    Used in show
    
## CANONICAL
    Function is shown as
    a + bi

## TRIGONOMETRIC
    Function is shown as
    r(cos(phi) + isin(phi))

## EXPONENTIAL
    Function is shown as
    re^(phi*i)


# Functions

## Calculating absolute value of z
```cpp
void calculateR();
```

## Calculating value of phi
```cpp
void calculatePhi();
```

## Return function conjugation
```cpp
Complex reflect();
```

## Airthmetic operators
    Allows to work with either Complex and double
```cpp
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
```
