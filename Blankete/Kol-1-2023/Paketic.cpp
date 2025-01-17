#include "Paketic.h"
#include <fstream>
using namespace std;

Paketic::Paketic() {
	niz = nullptr;
	max = 0;
	top = 0;
}

Paketic::Paketic(int max) {
	top = 0;
	this->max = max;
	niz = new Poklon* [max];
	for (int i = 0; i < max; i++)
	{
		niz[i] = nullptr;
	}
}

Paketic::Paketic(const Paketic& org){
	max = org.max;
	top = 0;
	niz = new Poklon * [max];
	for (int i = 0; i < org.top; i++)
	{
		this->Add(org.niz[i]->Clone());
	}
}

Paketic::~Paketic() {
	if (niz!=nullptr)
	{
		delete[] niz;
		niz = nullptr;
	}
}

void Paketic::Add(Poklon* obj) {
	if (top<max)
	{
		niz[top] = obj;
		top++;
	}
}

void Paketic::Save(const char* filename) {
	ofstream izlaz(filename);
	if (izlaz.good())
	{
		izlaz << *this;

		izlaz.close();
	}
}

Poklon* Paketic::Max() {
	Poklon* pom = niz[0];
	for (int i = 1; i < this->top; i++)
	{
		if (pom->BrojMasnica()<this->niz[i]->BrojMasnica())
		{
			pom = niz[i];
		}
	}
	return pom;
}

void Paketic::RemoveMinimum(Poklon* obj) {
	int pom = 0;
	for (int i = 0; i < this->top; i++)
	{
		if (this->niz[i] < this->niz[i+1])
		{
			pom = i + 1;
		}
	}
	delete niz[pom];
	niz[pom] = obj;
}

Paketic Paketic::operator+(Paketic& obj) {
	Paketic pom(this->max + obj.max);
	for (int i = 0; i < this->max; i++)
	{
		pom.Add(this->niz[i]->Clone());
	}
	for (int j = 0; j < obj.max; j++)
	{
		pom.Add(obj.niz[j]->Clone());
	}
	return pom;
}

Paketic& Paketic::operator=(Paketic& obj){
	if (this!=&obj)
	{
		max = obj.max;
		for (int i = 0; i < obj.top; i++)
		{
			this->Add(obj.niz[i]->Clone());
		}
	}
	return *this;
}

ostream& operator<<(ostream& izlaz, const Paketic& obj) {
	for (int i = 0; i < obj.max; i++)
	{
		if (obj.niz[i]!=nullptr)
		{
			izlaz << *obj.niz[i];
		}
	}
	return izlaz;
}