#include "FileSystemElement.h"

FileSystemElement::FileSystemElement() {
	ime = nullptr;
	ekstenzija = nullptr;
	roditelj = nullptr;
}

FileSystemElement::FileSystemElement(const char* ime, const char* ekstenzija, FileSystemElement* roditelj) {
	this->ime = new char[strlen(ime) + 1];
	strcpy(this->ime, ime);

	this->ekstenzija = new char[strlen(ekstenzija) + 1];
	strcpy(this->ekstenzija, ekstenzija);

	this->roditelj = roditelj;
}

FileSystemElement::~FileSystemElement() {
	if (ime != nullptr)
	{
		delete[] ime;
	}
	ime = nullptr;
	if (ekstenzija!=nullptr)
	{
		delete[] ekstenzija;
	}
	ekstenzija = nullptr;
	roditelj = nullptr;
}

ostream& operator<<(ostream& izlaz, const FileSystemElement& pom) {
	izlaz << pom.ime << "." << pom.ekstenzija << " ";
	return izlaz;
}