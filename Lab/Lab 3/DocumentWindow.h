#pragma once
#include "Window.h"
using namespace std;

class DocumentWindow :public Window {

public:
	DocumentWindow() {};
	DocumentWindow(const char* title, bool state):Window(title, state) {};
	virtual ~DocumentWindow() {};

	void draw() const { cout << "DocumentWindow nacrtan" << endl; };
};