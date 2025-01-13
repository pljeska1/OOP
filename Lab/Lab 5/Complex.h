#pragma once
#include <iostream>
using namespace std;

class Complex {
private:
	double real;
	double imag;
public:
	Complex();
	Complex(double _real, double _imag);
	Complex(const Complex& org);
	~Complex() {};

	Complex operator+(const Complex& br) const;
	Complex operator*(const Complex& br) const;
	Complex& operator=(const Complex& br);

	friend ostream& operator<<(ostream& izlaz, const Complex& br);
	friend istream& operator>>(istream& ulaz, Complex& br);
};