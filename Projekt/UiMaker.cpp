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

	/*for (int y = 6; y < maxy - 2; y++)
	{
		for (int x = maxx - 47; x < maxx - 3; x++)
		{
			setCursor(x, y);
			std::cout << "#";
		}
	}*/


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	setCursor(2, 2);
	std::cout << dir;


	setCursor(maxx - 47, 6);
	std::cout << "Up and Down arrows - navigate the list";

	setCursor(maxx - 47, 8);
	std::cout << "Enter - Open selected foder";

	setCursor(maxx - 47, 10);
	std::cout << "A - Open archiving setting";

	setCursor(maxx - 47, 12);
	std::cout << "Esc - Return to previous folder";

	setCursor(maxx - 47, 14);
	std::cout << "Del - Exit the program";


}

void UiMaker::updateContent()
{
	int files_size_x = maxx - 57;
	int files_size_y = maxy - 8;
	int files_start_x = 4;
	int files_start_y = 6;


	int files_show_start = 0;
	int new_cursor = cursor;

	int i_start = 0;
	int i_finish = files_size_y;

	if (cursor >= files_size_y)
	{
		files_show_start = (cursor / files_size_y) * files_size_y;
		new_cursor = cursor - files_show_start;
	}

	if (display_cursor == -1 || cursor / files_size_y != display_cursor / files_size_y)
	{
		i_start = 0;
		i_finish = files_size_y;

		display_cursor = cursor;
		
	}
	else
	{
		i_start = new_cursor - 1;
		i_finish = new_cursor + 1;
		if (i_start < 0) i_start = 0;
		
	}

	for (int i = i_start; i < files_size_y && i <= i_finish; i++)
	{

		for (int x = files_start_x - 2; x < files_size_x + files_start_x; x++)
		{
			setCursor(x, files_start_y + i);
			std::cout << ' ';
		}

		

		if (i + files_show_start < files.size())
		{
			if (files[i + files_show_start].getCopyDate() != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);
				setCursor(files_start_x - 2, files_start_y + i);
				std::cout << '*';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}

			if (i == new_cursor) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);

			setCursor(files_start_x, files_start_y + i);

			std::string s = files[i + files_show_start].getName();
			if (s.length() > files_size_x)
			{
				s = s.substr(0, files_size_x - 3) + "...";
			}
			std::cout << s;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		}

		
	}

}




UiMaker::UiMaker(std::vector <File> f, std::string d)
	:files(f), dir(d), cursor(0), display_cursor(-1)
{
	system("color f0");
}


void UiMaker::updateContent(std::vector<File> f, std::string d)
{
	dir = d;
	files = f;
	cursor = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);

	
	setCursor(2, 2);
	
	for (int i = 0; i < maxx - 4; i++)
		std::cout << ' ';
	
	setCursor(2, 2);
	std::cout << dir;

	display_cursor = -1;
	updateContent();
}

void UiMaker::cursorMove(int move)
{
	cursor += move;

	if (cursor < 0)
	{
		cursor = files.size() - 1;
		display_cursor = -1;
	}
	else if (cursor >= files.size())
	{
		cursor = 0;
		display_cursor = -1;
	}

	updateContent();
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
	display_cursor = -1;
}

