#include "File.h"
#include "Folder.h"
using namespace std;

File::File() : FileSystemElement() {};

File::File(const char* ime, const char* ekstenzija, FileSystemElement* roditelj) : FileSystemElement(ime, ekstenzija, roditelj){};


char* File::KvalifikovanoIme() {
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
	pom = string(this->ime) + '.' + string(this->ekstenzija);
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

void File::PrintList() {
	cout << "Fajlovi u istom folderu: " << endl;
	Folder* roditelj = (Folder*)(this->roditelj);
	int i = 0;
	while (roditelj->ReturnClan(i) != nullptr && i <= 2018)
	{
		if (typeid(*roditelj->ReturnClan(i)) == typeid(File))
		{
		cout << roditelj->ReturnClan(i)->KvalifikovanoIme() << endl;
		}
		i++;
	}
}