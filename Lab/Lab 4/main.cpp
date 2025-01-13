#include "File.h"
#include "Folder.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
	Folder* folder;
	Folder* folder2;
	Folder* folder3;
	File* fajl;
	File* fajl2;
	File* fajl3;
	
	ifstream ulaz("FileSystemElemenet.txt");

	if (ulaz.good())
	{
		char* ime = new char[10];
		char* eks = new char[4];

		ulaz.getline(ime, 10, ' ');
		ulaz.get();
		folder = new Folder(ime);
		ulaz.getline(ime, 10, ' ');
		ulaz.get();
		folder2 = new Folder(ime);
		ulaz.getline(ime, 10, ' ');
		ulaz.get();
		folder3 = new Folder(ime);

		ulaz.getline(ime, 10, ' ');
		ulaz.getline(eks, 4, ' ');
		ulaz.get();
		fajl = new File(ime, eks);
		ulaz.getline(ime, 10, ' ');
		ulaz.getline(eks, 4, ' ');
		ulaz.get();
		fajl2 = new File(ime, eks);
		ulaz.getline(ime, 10, ' ');
		ulaz.getline(eks, 4, ' ');
		ulaz.get();
		fajl3 = new File(ime, eks);

		delete[] ime;
		delete[] eks;
		ulaz.close();
	}

	folder->DodajElement(*folder2);
	folder->DodajElement(*folder3);
	folder2->DodajElement(*fajl);
	folder2->DodajElement(*fajl2);
	folder3->DodajElement(*fajl3);

	cout << fajl->KvalifikovanoIme() << endl << endl;

	fajl->PrintList();
	cout << endl;
	folder->PrintList();

	delete folder;
	return 0;
}