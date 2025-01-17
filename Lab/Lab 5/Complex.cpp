#include "Complex.h"

Complex::Complex() {
	real = 0;
	imag = 0;
}

Complex::Complex(double _real, double _imag) {
	real = _real;
	imag = _imag;
}

Complex::Complex(const Complex& org) {
	real = org.real;
	imag = org.imag;
}

Complex Complex::operator+(const Complex& br) const{
	return Complex(real + br.real, imag + br.imag);
}

Complex Complex::operator*(const Complex& br) const{
	return Complex(real*br.real-imag*br.imag, real*br.imag+imag*br.real);
}

Complex& Complex::operator=(const Complex& br) {
	if (this!=&br)
	{
		real = br.real;
		imag = br.imag;
	}
	return (*this);
}

ostream& operator<<(ostream& izlaz, const Complex& br) {
	izlaz << "Realni deo: " << br.real << " Imaginarni deo: " << br.imag << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, Complex& br) {
	ulaz >> br.real >> br.imag;
	return ulaz;
}