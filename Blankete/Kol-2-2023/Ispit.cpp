#include "Ispit.h"

Ispit::Ispit() {
	naziv = nullptr;
	ocena = 0;
	espb = 0;
}

Ispit::Ispit(char* _naziv, int _ocena, int _espb) {
	naziv = new char[strlen(_naziv) + 1];
	strcpy(naziv, _naziv);
	ocena = _ocena;
	espb = _espb;
}

Ispit::~Ispit() {
	if (naziv != nullptr) {
		delete[] naziv;
		naziv = nullptr;
	}
}

Ispit& Ispit::operator=(Ispit& pod) {
	naziv = new char[strlen(pod.naziv) + 1];
	strcpy(naziv, pod.naziv);
	ocena = pod.ocena;
	espb = pod.espb;
	return (*this);
}

bool Ispit::operator<(Ispit& pod) {
	return this->espb < pod.espb;
}


float& operator+=(float& pod1, Ispit& pod2) {
	pod1 += pod2.ocena;
	return pod1;
}

ostream& operator<<(ostream& izlaz, Ispit& pod) {
	izlaz << pod.naziv << " " << pod.ocena << " " << pod.espb << " ";
	return izlaz;
}

istream& operator>>(istream& ulaz, Ispit& pod) {
	char buffer[256];
	ulaz >> buffer >> pod.ocena >> pod.espb;
	pod.naziv = new char[strlen(buffer) + 1];
	strcpy(pod.naziv, buffer);
	return ulaz;
}