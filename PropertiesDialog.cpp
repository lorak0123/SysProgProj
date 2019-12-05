#include "PropertiesDialog.h"


void PropertiesDialog::updateContent()
{
	int x_start = maxx / 2 - 26;
	int y_start = maxy / 2 - 7;

	for (int i = 0; i < 7; i++)
	{
		if (i == cursor)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);

		setCursor(x_start + 9 + i * 6, y_start + 6);
		if (days_adapter.getDay(i)) std::cout << "*";
		else std::cout << " ";
	}
}


PropertiesDialog::PropertiesDialog(File f)
	:file(f), cursor(0), days_adapter(f.getCopyDate())
{
	
}

unsigned short PropertiesDialog::getDays()
{
	return days_adapter;
}

void PropertiesDialog::select()
{
	days_adapter.switchDay(cursor);
	updateContent();
}

void PropertiesDialog::move(int move)
{
	cursor += move;
	if (cursor < 0) cursor = 6;
	else if (cursor > 6) cursor = 0;

	updateContent();
}

void PropertiesDialog::show()
{
	int x_start = maxx/2 - 26;
	int y_start = maxy/2 - 7;
	int x_size = 55;
	int y_size = 14;


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	for (int y = y_start; y < y_size + y_start; y++)
	{
		for (int x = x_start; x < x_size + x_start; x++)
		{
			setCursor(x, y);
			std::cout << ' ';
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 51);


	for (int x = x_start + 2; x < x_size + x_start - 2; x++)
	{
		setCursor(x, y_start + 1);
		std::cout << '#';
		setCursor(x, y_start + y_size - 2);
		std::cout << '#';
	}

	for (int y = y_start + 2; y < y_size + y_start - 2; y++)
	{
		setCursor(x_start + 2, y);
		std::cout << '#';
		setCursor(x_start + x_size -3, y);
		std::cout << '#';
	}



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);

	setCursor(x_start + 6, y_start + 3);
	std::cout << "-------------------------------------------";
	setCursor(x_start + 6, y_start + 4);
	std::cout << "| mon | tu  | wed | thu | fri | sat | sun |";
	setCursor(x_start + 6, y_start + 5);
	std::cout << "-------------------------------------------";
	setCursor(x_start + 6, y_start + 6);
	std::cout << "| [ ] | [ ] | [ ] | [ ] | [ ] | [ ] | [ ] |";
	setCursor(x_start + 6, y_start + 7);
	std::cout << "-------------------------------------------";


	setCursor(x_start + 7, y_start + 9);
	std::cout << "-> & <- - rigth & left, space - select";
	setCursor(x_start + 7, y_start + 10);
	std::cout << "Press ESC to cancel or Enter to confirm.";

	updateContent();
	
}
