#include "UiMaker.h"


void UiMaker::drawFrame()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 51);

	
	for (int i = 0; i < maxx; i++)
	{
		setCursor(i, 0);
		std::cout << "#";
		setCursor(i, 4);
		std::cout << "#";
		setCursor(i, maxy - 1);
		std::cout << "#";
	}
	for (int i = 0; i < maxy; i++)
	{
		setCursor(0, i);
		std::cout << "#";
		setCursor(maxx - 1, i);
		std::cout << "#";
	}

	for (int i = 5; i < maxy; i++)
	{
		setCursor(maxx - 50, i);
		std::cout << "#";
	}


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	setCursor(2, 2);
	std::cout << dir;

	setCursor(10, 10);


}

void UiMaker::updateContent()
{
	int files_size_x = maxx - 57;
	int files_size_y = maxy - 8;
	int files_start_x = 4;
	int files_start_y = 6;

	/*for (int y = files_start_y; y < files_size_y + files_start_y; y++)
	{
		for (int x = files_start_x; x < files_size_x + files_start_x; x++)
		{
			setCursor(x, y);
			std::cout << '*';
		}
	}*/

	for (int i = 0; i < files.size(); i++)
	{

		if (files[i].getCopyDate() != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);
			setCursor(files_start_x - 2, files_start_y + (i));
			std::cout << '*';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		}

		if (i == cursor) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		else if (i == cursor + 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);

		setCursor(files_start_x, files_start_y + (i));
		std::cout << files[i].getName();
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
}

void UiMaker::updateRange()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	maxx = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	maxy = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void UiMaker::setCursor(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void UiMaker::getCursor(int* x, int* y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	*x = csbi.dwCursorPosition.X;
	*y = csbi.dwCursorPosition.Y;
}

UiMaker::UiMaker(std::vector <File> f, std::string d)
	:files(f), dir(d), cursor(0)
{
	updateRange();
	system("color f0");
}

bool UiMaker::sizeChanges()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (maxx != csbi.srWindow.Right - csbi.srWindow.Left + 1 ||
		maxy != csbi.srWindow.Bottom - csbi.srWindow.Top + 1) return true;
	else return false;
}

void UiMaker::updateContent(std::vector<File> f, std::string d)
{
	dir = d;
	files = f;
}

void UiMaker::cursorMove(int move)
{
	cursor += move;

	if (cursor < 0) cursor = files.size() - 1;
	else if (cursor >= files.size()) cursor = 0;

	updateContent();
}

void UiMaker::clearScreen()
{
	system("cls");
}

File UiMaker::getFile()
{
	return files[cursor];
}


void UiMaker::draw()
{
	if (sizeChanges()) updateRange();
	drawFrame();
	updateContent();
}

void UiMaker::refresh()
{
	clearScreen();
	updateRange();
	draw();
}

void UiMaker::getRange(int* x, int* y)
{
	updateRange();
	*x = maxx;
	*y = maxy;
}