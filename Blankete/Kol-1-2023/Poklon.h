#pragma once
#include <iostream>
using namespace std;

class Poklon {
protected:	
	double cena;
	int masnice;
public:
	Poklon();
	Poklon(double cena, int masnice);
	Poklon(Poklon& org);
	virtual ~Poklon();

	virtual Poklon* Clone() = 0;
	virtual int BrojMasnica() = 0;
	
	virtual void prikazi(ostream& izlaz) const;
	friend ostream& operator<<(ostream& izlaz, const Poklon& obj);
};