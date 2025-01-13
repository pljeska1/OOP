#include "Window.h"
using namespace std;

Window::Window() {
	title = nullptr;
}

Window::Window(const char* title, bool state):state(state) {
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

Window::~Window() {
	if (title!=nullptr)
	{
		delete[] title;
	}
	title = nullptr;
}

void Window::draw() const{
 	cout << title << " : ";
	if (state == true)
		cout << "Otvoren";
	else
		cout << "Zatvoren";
	cout << endl;
}

Window& Window::operator=(const Window& pom) {
	if (this!=&pom)
	{
		if (this->title != nullptr)
		{
			delete[] this->title;
		}

		this->title = new char[strlen(pom.title) + 1];
		strcpy(this->title, pom.title);
		this->state = pom.state;
	}
	return *this;
}

ostream& operator<<(ostream& izlaz, const Window& pom) {
	izlaz << pom.title << " : ";
	if (pom.state == false)
		izlaz << "Zatvoren";
	else
		izlaz << "Otvoren";
	izlaz << endl;

	return izlaz;
}