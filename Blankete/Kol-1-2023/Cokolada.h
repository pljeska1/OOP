#pragma once
#include "Poklon.h"
#include <iostream>
using namespace std;

class Cokolada : public Poklon {
private:
	int kakao;
public:
	Cokolada();
	Cokolada(double cena, int masnice, int kakao);
	Cokolada(Cokolada& org);
	~Cokolada();

	Poklon* Clone() { return new Cokolada(*this); }
	int BrojMasnica() { return this->masnice * 2; }

	void prikazi(ostream& izlaz) const;
};