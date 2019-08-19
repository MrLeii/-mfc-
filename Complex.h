#pragma once
#include "afxwin.h"
#include <iostream>

using namespace std;

class Complex
{

public:
	Complex(double real=0.0, double imag = 0.0)
		:_Real(real),_Imag(imag){}

	double real();
	double imag();

	void setComplex(double, double);

	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);
	Complex operator*(const int&);
	Complex operator=(const Complex&);
	Complex operator+=(const Complex&);
	Complex operator-=(const Complex&);
	Complex operator*=(const Complex&);
	Complex operator*=(const int&);
	Complex operator/=(const Complex&);
	//friend istream& operator>>(istream&, Complex&);
	//friend ostream& operator<<(ostream&, const Complex&);

private:
	double _Real, _Imag;
};