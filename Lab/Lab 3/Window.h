#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Window {
private:
	char* title;
	bool state; //false-zatvoren;true-otvoren
public:
	Window();
	Window(const char* title, bool state);
	virtual ~Window();

	virtual void draw() const;
	void open() { state = true; };
	void close() { state = false; };
	char* ReturnTitle() { return this->title; }
	Window& operator=(const Window& pom);
	friend ostream& operator<<(ostream& izlaz, const Window& pom);
};