#pragma once
#include <iostream>
using namespace std;

class ProsireniPodatak {
private:
	float T;
	float E;
	float V;
public:
	ProsireniPodatak();
	ProsireniPodatak(float _T, float _E, float _V);
	ProsireniPodatak(const ProsireniPodatak& o);
	~ProsireniPodatak() {}

	float subOsecaj() const { return T + 0.33 * E - 0.7 * V - 4.0; }

	ProsireniPodatak& operator=(const ProsireniPodatak& o);
	friend float& operator+=(float& pom, const ProsireniPodatak& pod);
	bool operator>(const ProsireniPodatak& pod);

	friend ostream& operator<<(ostream& izlaz, ProsireniPodatak& pod);
	friend istream& operator>>(istream& ulaz, ProsireniPodatak& pod);
};