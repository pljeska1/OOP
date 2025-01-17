#include "DocumentWindow.h"
#include "DialogWindow.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	Window** niz = new Window* [2018];

	ifstream ulazni_file("Prozori_ulaz.txt");

	if (ulazni_file.good())
	{
		char* buffer = new char[6];
		int stanje;

		for (int i = 0; i < 1009; i++)
		{
			ulazni_file.getline(buffer, 6, ' ');
			ulazni_file >> stanje;
			ulazni_file.get();
			niz[i] = new DialogWindow(buffer, stanje);
		}
		for (int i = 1009; i < 2018; i++)
		{
			ulazni_file.getline(buffer, 6, ' ');
			ulazni_file >> stanje;
			ulazni_file.get();
			niz[i] = new DocumentWindow(buffer, stanje);
		}
		delete[] buffer;
		ulazni_file.close();
	}

	niz[5]->draw();
	niz[1105]->draw();

	niz[10]->open();
	niz[10]->Window::draw();

	niz[1111]->close();
	niz[1111]->Window::draw();

	Window* pom = new Window();
	for (int i = 0; i < 2017; i++)
	{
		for (int j = 0; j < 2018; j++)
		{
			if (strcmp(niz[i]->ReturnTitle(), niz[j]->ReturnTitle()) < 0)
			{
				*pom = *niz[i];
				*niz[i] = *niz[j];
				*niz[j] = *pom;
			}
		}
	}

	ofstream izlazni_file("Prozori_izlaz.txt");
	if (izlazni_file.good())
	{
		for (int i = 0; i < 2018; i++)
		{
			izlazni_file << *niz[i];
		}
		izlazni_file.close();
	}

	for (int i = 0; i < 2018; i++)
	{
		delete niz[i];
	}
	delete[] niz;
	niz = nullptr;

	DialogWindow prozor("Prozor", 1);
	prozor.confirm();
	cout << prozor;
	prozor.cancel();
	cout << prozor;

	return 0;
}