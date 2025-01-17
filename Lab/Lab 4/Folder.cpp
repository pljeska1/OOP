#pragma once
#include "Folder.h"
#include "File.h"
using namespace std;

Folder::Folder() : FileSystemElement() {
	clan = nullptr;
}

Folder::Folder(const char* ime, FileSystemElement* roditelj): FileSystemElement(ime, "", roditelj)
{
	clan = new FileSystemElement*[2018];
	for (int i = 0; i < 2018; i++)
	{
		clan[i] = nullptr;
	}
}

Folder::~Folder() {
	if (clan!=nullptr)
	{
		int i = 0;
		while (clan[i] != nullptr) {
			delete clan[i];
			clan[i] = nullptr;
		}
		delete[] clan;
	}
	clan = nullptr;
}

char* Folder::KvalifikovanoIme() {
	string pom2;
	if (this->roditelj != nullptr)
	{
		pom2 = string(this->roditelj->KvalifikovanoIme());
	}
	else
	{
		pom2 = "";
	}
	string pom;
	pom = string(this->ime) + '/';
	if (pom2 != "")
	{
		pom2 = pom2 + pom;
		char* rezultat = new char[pom2.length() + 1];
		strcpy(rezultat, pom2.c_str());
		return rezultat;
	}
	char* rezultat = new char[pom.length() + 1];
	strcpy(rezultat, pom.c_str());
	return rezultat;
}

void Folder::PrintList() {
	int i = 0;
	cout << this->ime << ":" << endl;
	while (clan[i]!=nullptr && i<=2018)
	{
		if (typeid(*clan[i]) == typeid(Folder))
			clan[i]->PrintList();
		else if (typeid(*clan[i]) == typeid(File))
			cout << clan[i]->KvalifikovanoIme() << endl;
		i++;
	}
}

void Folder::DodajElement(FileSystemElement& podelement) {
	int i = 0;
	while(clan[i] != nullptr && i < 2018)
	{
		i++;
	}
	if (i >= 2018)
	{
		cout << "Nema mesta u Folderu!";
		return;
	}
	else {
		clan[i] = &podelement;
		podelement.SetRoditelj(this);
		return;
	}
}

void Folder::BrisiElement(int i) {
	if (clan[i]!=nullptr)
	{
	clan[i]->SetRoditelj(nullptr);
	clan[i] = nullptr;
	}
}