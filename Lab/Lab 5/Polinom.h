#pragma once
#include <iostream>
using namespace std;

template <class Type, int n>
class Polinom {
private:
	Type niz[n + 1];
public:
	Polinom() {
		for (int i = 0; i <= n; i++)
		{
			niz[i] = Type();
		}
	}
	
	void Unesi() {
		for (int i = 0; i <= n; i++)
		{
			cin >> niz[i];
		}
	}

	Type Izracunaj(Type x) {
		Type rez = Type();
		int i;
		for (i = 0; i <= n; i++)
		{
			Type pom;
			if (i == 0)
			{
				rez = rez + niz[i];
			}
			else
			{
				pom = x;
				for (int j = 1; j < i; j++)
				{
					pom = pom * x;
				}
				rez = rez + niz[i] * pom;
			}
		}
		return rez;
	}
};