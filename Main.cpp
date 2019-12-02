#include <iostream>
#include "UiMaker.h"
#include "KeyboardMenager.h"
#include "PropertiesDialog.h"
#include <vector>


using namespace std;



int main(void)
{
	UiMaker ui = UiMaker();

	vector<File> files =
	{
		File("ASP .NET", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("C#", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("C++", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania", 1, 12),
		File("JAVA", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("PRIR", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania", 2, 12),
		File("Programowanie Projekt", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("ProgSysWindows", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("Projekt Wnek", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("Zadania projektowe C   IP11 s1.docx", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania")
	};

	ui.updateContent(std::move(files), "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania");

	ui.draw();

	for (;;)
	{
		int key = KeyboardMenager::listen();

		if (key == 80)
		{
			ui.cursorMove(1);
		}
		else if (key == 72)
		{
			ui.cursorMove(-1);
		}
		else if (key == 97 || key == 65)
		{
			PropertiesDialog dial = PropertiesDialog(ui.getFile());
			while (!dial.IsSet)
			{
				dial.show();
				
				cout << KeyboardMenager::listen();
			}
		}



		cout << key << ' ';

		
		if (ui.sizeChanges()) ui.refresh();
	}
	

	/*system("color f0");

	for (int colour = 0x00; colour <= 0xff; colour++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
			
		std::cout << "Using colour:" << colour << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		std::cout << "Using colour:" << colour << std::endl;
		std::cout << "Using colour:" << colour << std::endl;
		std::cout << "Using colour:" << colour << std::endl;

		cin.get();
	}*/

	system("pause");
}
