#pragma once
#include "Poklon.h"
#include <iostream>
using namespace std;

class Igracka : public Poklon {
private:
	char* tip;
public:
	Igracka();
	Igracka(double cena, int masnice, const char* tip);
	Igracka(Igracka& org);
	~Igracka();

	Poklon* Clone() { return new Igracka(*this); }
	int BrojMasnica() { return this->masnice + 2; }

	void prikazi(ostream& izlaz) const;
};