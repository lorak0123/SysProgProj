#include "Window.h"

void Window::updateRange()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	maxx = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	maxy = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Window::setCursor(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void Window::getCursor(int* x, int* y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	*x = csbi.dwCursorPosition.X;
	*y = csbi.dwCursorPosition.Y;
}

Window::Window()
{
	updateRange();
}

bool Window::sizeChanges()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (maxx != csbi.srWindow.Right - csbi.srWindow.Left + 1 ||
		maxy != csbi.srWindow.Bottom - csbi.srWindow.Top + 1) return true;
	else return false;
}


void Window::getRange(int* x, int* y)
{
	updateRange();
	*x = maxx;
	*y = maxy;
}

void Window::clearScreen()
{
	system("cls");
}
