#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Novcanik {
private:
	int max;
	int top;
	T* niz;
public:
	Novcanik();
	Novcanik(int _max);
	~Novcanik();

	void Dodaj(T el);
	void Izbaci(T el);
	float Ukupno();
	int UkupniBrojVrednost(T vrednost, float& ukupnaVrednost);
	int NajmanjeNovcanica(int cena);

	void Sacuvaj(const char* fajl);
	void Ucitaj(const char* fajl);
	friend ostream& operator<<(ostream& izlaz, Novcanik<T>& pod) {
		for (int i = 0; i < pod.top; i++)
			izlaz << pod.niz[i] << " ";
		return izlaz;
	}
};

template<class T>
inline Novcanik<T>::Novcanik() {
	max = top = 0;
	niz = nullptr;
}

template<class T>
inline Novcanik<T>::Novcanik(int _max) {
	max = _max;
	top = 0;
	niz = new T[max];
}

template<class T>
inline Novcanik<T>::~Novcanik() {
	if (niz != nullptr) delete[] niz;
	niz = nullptr;
}

template<class T>
inline void Novcanik<T>::Dodaj(T el) {
	if (top >= max) throw "Overflow Kolekcije!";
	int i = 0;
	while (i < top && niz[i] > el)
		i++;
	for (int j = top; j > i; j--)
		niz[j] = niz[j - 1];
	niz[i] = el;
	top++;
}

template<class T>
inline void Novcanik<T>::Izbaci(T el) {
	int i = 0;
	bool postoji = false;

	while (i < top && !postoji) {
		if (el == niz[i]) postoji = true;
		i++;
	}

	if (!postoji) throw "Datog elementa nema u kolekciji!";

	i--;
	for (; i < top - 1; i++)
		niz[i] = niz[i + 1];
	top--;
}

template<class T>
inline float Novcanik<T>::Ukupno() {
	float pom = 0.0f;

	for (int i = 0; i < top; i++)
		pom = niz[i] + pom;

	return pom;
}

template<class T>
inline int Novcanik<T>::UkupniBrojVrednost(T vrednost, float& ukupnaVrednost) {
	int brojac = 0;
	ukupnaVrednost = 0.0f;

	for (int i = 0; i < top; i++) {
		if (niz[i] == vrednost) {
			ukupnaVrednost = niz[i] + ukupnaVrednost;
			brojac++;
		}
	}

	return brojac;
}

template<class T>
inline int Novcanik<T>::NajmanjeNovcanica(int cena) {
	float vrednost = 0.0f;
	int i = 0;

	while (vrednost < cena && i < top) {
		vrednost = niz[i] + vrednost;
		i++;
	}
	
	if (vrednost >= cena) return i;
	else return 0;
}

template<class T>
inline void Novcanik<T>::Sacuvaj(const char* fajl) {
	ofstream izlaz(fajl);
	if (!izlaz.good()) throw "Doslo je do greske pri otvaranju fajla!";

	for (int i = 0; i < top; i++)
		izlaz << niz[i] << " ";
	izlaz.close();
}

template<class T>
inline void Novcanik<T>::Ucitaj(const char* fajl) {
	ifstream ulaz(fajl);
	if (!ulaz.good()) throw "Doslo je do greske pri otvaranju fajla!";

	T pom;
	while (ulaz >> pom) {
		if (top >= max) throw "Overflow kolekcije!";
		niz[top++] = pom;
	}
	ulaz.close();
}