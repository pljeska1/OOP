#pragma once
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

template<class T>
class Kolekcija {
private:
	int max;
	int top;
	T* niz;
public:
	Kolekcija() { max = 0; top = 0; niz = nullptr; }
	Kolekcija(int n);
	~Kolekcija();

	void DodajPodatak(T& pod);
	void Obrisi(int n);
	float OdrediProsek();
	T NajveciPodatak();

	friend ostream& operator<<(ostream& izlaz, const Kolekcija<T>& pod) {
		for (int i = 0; i < pod.top; i++)
			izlaz << pod.niz[i] << " ";
		return izlaz;
	}
	friend istream& operator>>(istream& ulaz, Kolekcija<T>& pod);
	void Sacuvaj(const char* ime);
	void Ucitaj(const char* ime);
};

template<class T>
Kolekcija<T>::Kolekcija(int n) {
	max = n;
	top = 0;
	niz = new T[max];
}

template<class T>
Kolekcija<T>::~Kolekcija() {
	if (niz != nullptr) {
		delete[] niz;
		niz = nullptr;
	}
}

template<class T>
void Kolekcija<T>::DodajPodatak(T& pod) {
	if (max == top) throw exception("Nema vise mesta");
	else {
		niz[top] = pod;
		top++;
	}
}

template<class T>
void Kolekcija<T>::Obrisi(int broj) {
	if (broj > top) throw exception("Ne postoji podatak");
	else {
		for (int i = broj - 1; i < top - 1; i++)
			niz[i] = niz[i + 1];
		top--;
	}
}

template<class T>
float Kolekcija<T>::OdrediProsek() {
	float pros = 0;
	for (int i = 0; i < top; i++)
		pros += niz[i];
	return pros/top;
}


template<class T>
T Kolekcija<T>::NajveciPodatak() {
	T naj = niz[0];
	for (int i = 1; i < top; i++)
		if (naj < niz [i])
			naj = niz[i];
	return naj;
}

template<class T>
void Kolekcija<T>::Sacuvaj(const char* ime) {
	ofstream fajl(ime, ios::out);
	if (!fajl.good()) throw exception("Fajl nije otvoren");
	
	for (int i = 0; i < this->top; i++)
		fajl << this->niz[i] << endl;

	fajl.close();
}

template<class T>
void Kolekcija<T>::Ucitaj(const char* ime) {
	ifstream fajl(ime);
	if (!fajl.good()) throw exception("Fajl nije otvoren");
	
	T temp;
	while (fajl >> temp) {
		if (top >= max) {
			fajl.close();
			throw exception("Kolekcija Overflow");
		}
		niz[top] = temp;
		top++;
	}

	fajl.close();
}