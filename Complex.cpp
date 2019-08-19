#include "stdafx.h"
#include "Complex.h"

using namespace std;


double Complex::real()
{
	return _Real;
}

double Complex::imag()
{
	return _Imag;
}

void Complex::setComplex(double num1, double num2)
{
    _Real = num1; 
    _Imag = num2;
}

Complex Complex::operator+(const Complex& complex)
{
	Complex myComplex(0,0);
	myComplex += *this;
	myComplex += complex;

	return myComplex;
}

Complex Complex::operator-(const Complex& complex)
{
	Complex myComplex(0,0);
	myComplex += *this;
	myComplex -= complex;

	return myComplex;
}

Complex Complex::operator*(const Complex& complex)
{
	Complex myComplex(0,0);
	myComplex += *this;
	myComplex *= complex;

	return myComplex;
}

Complex Complex::operator*(const int& num)
{
	Complex myComplex(0,0);
	myComplex += *this;
	myComplex *= num;

	return myComplex;
}

Complex Complex::operator=(const Complex& complex)
{
	this->_Real = complex._Real;
	this->_Imag = complex._Imag;

	return *this;
}

Complex Complex::operator+=(const Complex& complex)
{
	this->_Real += complex._Real;
	this->_Imag += complex._Imag;

	return *this;
}

Complex Complex::operator-=(const Complex& complex)
{
	this->_Real -= complex._Real;
	this->_Imag -= complex._Imag;

	return *this;
}

Complex Complex::operator*=(const Complex& complex)
{
	Complex myComplex = *this;
	this->_Real = (myComplex._Real*complex._Real)-(myComplex._Imag*complex._Imag);
	this->_Imag = (myComplex._Real*complex._Imag)+(myComplex._Imag*complex._Real);

	return *this;
}

Complex Complex::operator*=(const int& num)
{
	Complex myComplex = *this;
	this->_Real = this->_Real*num;
	this->_Imag = this->_Imag*num;

	return *this;
}

Complex Complex::operator/=(const Complex& complex)
{
	double a = this->_Real;
	double b = this->_Imag;
	double c = complex._Real;
	double d = complex._Imag;

	this->_Real = ((a*c)+(b*d))/((c*c)+(d*d));
	this->_Imag = ((b*c)-(a*d))/((c*c)+(d*d));

	return *this;
}

/*
istream& operator>>(istream& is, Complex& complex)
{
	is >> complex._Real;
	is >> complex._Imag;

	return is;
}
*/

/*
ostream& operator<<(ostream& os, const Complex& complex)
{
	if(complex._Real>=0) os << " ";
	os << complex._Real;
	if(complex._Imag>=0) os << "+";
	os << complex._Imag << "i";

	return os;
}
*/