#include "DialogWindow.h"
using namespace std;

void DialogWindow::draw() const {
	cout << "DialogWindow nacrtan" << endl;
}

int DialogWindow::confirm() {
	this->close();
	return 1;
}

int DialogWindow::cancel() {
	this->close();
	return 0;
}