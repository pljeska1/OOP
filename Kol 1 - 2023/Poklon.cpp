#include "Poklon.h"

Poklon::Poklon() {
	cena = 0;
	masnice = 0;
}

Poklon::Poklon(double cena, int masnice) {
	this->cena = cena;
	this->masnice = masnice;
}

Poklon::Poklon(Poklon& org) {
	this->cena = org.cena;
	this->masnice = org.masnice;
}

Poklon::~Poklon(){}

void Poklon::prikazi(ostream& izlaz) const {
	izlaz << "Cena je " << cena << endl;
	izlaz << "Broj masnica je " << masnice << endl;
}

ostream& operator<<(ostream& izlaz, const Poklon& obj) {
	obj.prikazi(izlaz);
	return izlaz;
}