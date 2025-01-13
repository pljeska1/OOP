#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class FileSystemElement {
protected:
	char* ime;
	char* ekstenzija;
	FileSystemElement* roditelj; //nullptr ako nema roditelja
public:
	FileSystemElement();
	FileSystemElement(const char* ime, const char* ekstenzija, FileSystemElement* roditelj = nullptr);
	virtual ~FileSystemElement();

	void SetRoditelj(FileSystemElement* novi_roditelj) { this->roditelj = novi_roditelj; };
	virtual char* KvalifikovanoIme() = 0;
	virtual void PrintList() = 0;
	friend ostream& operator<<(ostream& izlaz, const FileSystemElement& pom);
};