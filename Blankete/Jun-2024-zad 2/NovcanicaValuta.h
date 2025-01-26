#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class NovcanicaValuta {
private:
	char* oz;
	int vred;
	float kurs;
public:
	NovcanicaValuta();
	NovcanicaValuta(char* _oz, int _vred, float _kurs);
	NovcanicaValuta(const NovcanicaValuta& og);
	~NovcanicaValuta();

	NovcanicaValuta& operator=(const NovcanicaValuta& og);
	bool operator>(const NovcanicaValuta& og);
	bool operator==(const NovcanicaValuta& og);
	float operator+(float& broj);

	friend ostream& operator<<(ostream& izlaz, NovcanicaValuta& pod);
	friend istream& operator>>(istream& ulaz, NovcanicaValuta& pod);
};