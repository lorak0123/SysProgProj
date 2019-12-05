#pragma once
#include <windows.h>
#include <iostream>


class Window
{
protected:
	int maxx;
	int maxy;
	void updateRange();
	void setCursor(int x, int y);
	void getCursor(int* x, int* y);

public:
	Window();
	bool sizeChanges();
	void getRange(int* x, int* y);
	void clearScreen();
};

