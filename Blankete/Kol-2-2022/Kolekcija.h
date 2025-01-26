#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Kolekcija {
private:
	int max;
	int top;
	T* niz;
public:
	Kolekcija() {
		max = top = 0;
		niz = nullptr;
	}

	Kolekcija(int _max) {
		max = _max;
		top = 0;
		niz = new T[max];
	}

	~Kolekcija() {
		if(niz != nullptr)
			delete[] niz;
	}

	void DodajPodatak(T podatak) {
		if (top >= max) throw exception("Prekoracenje velicine niza!");
		niz[top++] = podatak;
	}

	friend ostream& operator<<(ostream& izlaz, Kolekcija& podatak) {
		for (int i = 0; i < podatak.top; i++) {
			izlaz << podatak.niz[i] << " ";
		}
		return izlaz;
	}

	void Obrisi(int n) {
		if (n >= top) throw exception("Ovaj podatak ne postoji!");
		for (int i = n - 1; i < top - 1; i++)
			niz[i] = niz[i + 1];
		top--;
	}

	float OdrediProsek() {
		float pom = 0.0f;
		for (int i = 0; i < top; i++)
			pom += niz[i];
		return pom / top;
	}

	T NajveciPodatak() {
		T pom = niz[0];
		for (int i = 1; i < top; i++)
			if (niz[i] > pom)
				pom = niz[i];
		return pom;
	}

	void Sacuvaj(const char* fajl) {
		ofstream izlazFajl(fajl);
		if (!izlazFajl.good()) throw exception("Doslo je do greske pri upisu u fajl!");

		for (int i = 0; i < top; i++)
			izlazFajl << niz[i] << endl;
		izlazFajl.close();
	}

	void Ucitaj(const char* fajl) {
		ifstream ulazniFajl(fajl);
		if (!ulazniFajl.good()) throw exception("Doslo je do greske pri citanju iz fajla!");

		T pom;
		while (ulazniFajl >> pom) {
			if (top >= max) {
				ulazniFajl.close();
				throw exception("Overflow Kolekcije");
			}
			niz[top++] = pom;
		}
		ulazniFajl.close();
	}
};