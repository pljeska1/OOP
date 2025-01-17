#include "Igracka.h"
#include <string>

Igracka::Igracka() : Poklon() {
	tip = nullptr;
}

Igracka::Igracka(double cena, int masnice, const char* tip) : Poklon(cena, masnice) {
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
}
Igracka::Igracka(Igracka& org) : Poklon(org) {
	this->tip = new char[strlen(org.tip) + 1];
	strcpy(this->tip, org.tip);
}

Igracka::~Igracka() {
	if (tip!=nullptr)
	{
		delete[] tip;
		tip = nullptr;
	}
}

void Igracka::prikazi(ostream& izlaz) const{
	Poklon::prikazi(izlaz);
	izlaz << "Tip materijala " << tip << endl;
}