#include "NovcanicaValuta.h"

NovcanicaValuta::NovcanicaValuta() {
	oz = nullptr;
	vred = 0;
	kurs = 0;
}

NovcanicaValuta::NovcanicaValuta(char* _oz, int _vred, float _kurs) {
	oz = new char[strlen(_oz) + 1];
	strcpy(oz, _oz);
	vred = _vred;
	kurs = _kurs;
}

NovcanicaValuta::NovcanicaValuta(const NovcanicaValuta& og) {
	oz = new char[strlen(og.oz) + 1];
	strcpy(oz, og.oz);
	vred = og.vred;
	kurs = og.kurs;
}

NovcanicaValuta::~NovcanicaValuta() {
	if (oz != nullptr) delete[] oz;
	oz = nullptr;
}

NovcanicaValuta& NovcanicaValuta::operator=(const NovcanicaValuta& og) {
	if (this != &og) {
		oz = new char[strlen(og.oz) + 1];
		strcpy(oz, og.oz);
		vred = og.vred;
		kurs = og.kurs;
	}
	return *this;
}

bool NovcanicaValuta::operator>(const NovcanicaValuta& og) {
	if (vred * kurs > og.vred * og.kurs) return true;
	else return false;
}

bool NovcanicaValuta::operator==(const NovcanicaValuta& og) {
	if (!strcmp(oz, og.oz) && vred == og.vred) return true;
	else return false;
}

float NovcanicaValuta::operator+(float& broj) {
	return broj + vred * kurs;
}

ostream& operator<<(ostream& izlaz, NovcanicaValuta& pod) {
	izlaz << pod.oz << " " << pod.vred << " " << pod.kurs;
	return izlaz;
}
	
istream& operator>>(istream& ulaz, NovcanicaValuta& pod) {
	char buffer[256];
	ulaz >> buffer >> pod.vred >> pod.kurs;
	pod.oz = new char[strlen(buffer) + 1];
	strcpy(pod.oz, buffer);
	return ulaz;
}