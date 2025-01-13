#include <iostream>
#include "Complex.h"
#include "Polinom.h"
using namespace std;

int main() {
	Polinom<int, 3> Realni_Polinom;
	Realni_Polinom.Unesi();
	int x = 2;
	cout << Realni_Polinom.Izracunaj(x) << endl;

	Polinom<Complex, 3> Kompleksni_Polinom;
	Kompleksni_Polinom.Unesi();
	Complex y(1, 1);
	cout << Kompleksni_Polinom.Izracunaj(y);

	return 0;
}