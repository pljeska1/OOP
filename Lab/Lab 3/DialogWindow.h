#include "Window.h"

class DialogWindow : public Window {

public:
	DialogWindow() {};
	DialogWindow(const char* title, bool state) : Window(title, state) {};
	virtual ~DialogWindow() {};

	void draw() const;
	int confirm();
	int cancel();
};