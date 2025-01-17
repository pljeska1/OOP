#include "Cokolada.h"


Cokolada::Cokolada() : Poklon() {
	kakao = 0;
}

Cokolada::Cokolada(double cena, int masnice, int kakao) : Poklon(cena, masnice) {
	this->kakao = kakao;
}

Cokolada::Cokolada(Cokolada& org) : Poklon(org) {
	this->kakao = org.kakao;
}

Cokolada::~Cokolada() {}


void Cokolada::prikazi(ostream& izlaz) const{
	Poklon::prikazi(izlaz);
	izlaz << "Kakao " << kakao << endl;
}