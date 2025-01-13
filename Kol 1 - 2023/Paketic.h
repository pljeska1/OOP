#pragma once
#include "Cokolada.h"
#include "Igracka.h"
#include <iostream>
using namespace std;

class Paketic {
private:
	Poklon** niz;
	int max;
	int top;
public:
	Paketic();
	Paketic(int max);
	Paketic(const Paketic& org);
	~Paketic();

	int BrojPoklona() const { return max; }
	void Add(Poklon* obj);

	void Save(const char* filename);

	Poklon* Max();
	void RemoveMinimum(Poklon* obj);

	Paketic operator+(Paketic& obj);
	Paketic& operator=(Paketic& obj);
	friend ostream& operator<<(ostream& izlaz, const Paketic& obj);
};