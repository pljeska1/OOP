#include "ProsireniPodatak.h"

ProsireniPodatak::ProsireniPodatak() {
	T = E = V = 0;
}

ProsireniPodatak::ProsireniPodatak(float _T, float _E, float _V) {
	T = _T;
	E = _E;
	V = _V;
}

ProsireniPodatak::ProsireniPodatak(const ProsireniPodatak& o) {
	T = o.T;
	E = o.E;
	V = o.V;
}

ProsireniPodatak& ProsireniPodatak::operator=(const ProsireniPodatak& o) {
	if (this != &o) {
		this->T = o.T;
		this->E = o.E;
		this->V = o.V;
	}
	return *this;
}

float& operator+=(float& pom, const ProsireniPodatak& pod) {
	pom += pod.subOsecaj();
	return pom;
}

bool ProsireniPodatak::operator>(const ProsireniPodatak& pod) {
	if (this->subOsecaj() > pod.subOsecaj()) return true;
	else return false;
}

ostream& operator<<(ostream& izlaz, ProsireniPodatak& pod) {
	izlaz << pod.T << " " << pod.E << " " << pod.V;
	return izlaz;
}

istream& operator>>(istream& ulaz, ProsireniPodatak& pod) {
	ulaz >> pod.T >> pod.E >> pod.V;
	return ulaz;
}