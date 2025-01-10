#pragma once
#include <iostream>
#include <exception>
#include <string.h>
using namespace std;

class Ispit {
private:
	char* naziv;
	int ocena;
	int espb;
public:
	Ispit();
	Ispit(char* _naziv, int _ocena, int _espb);
	~Ispit();

	int getOcena() { return ocena; }

	Ispit& operator=(Ispit& pod);
	bool operator<(Ispit& pod);
	friend float& operator+=(float& pod1, Ispit& pod2);

	friend ostream& operator<<(ostream& izlaz, Ispit& pod);
	friend istream& operator>>(istream& ulaz, Ispit& pod);
};