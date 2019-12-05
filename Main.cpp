#include <iostream>
#include "UiMaker.h"
#include "KeyboardMenager.h"
#include "PropertiesDialog.h"
#include <vector>
#include "CopyDaysAdapter.h"


using namespace std;


File setFileProperties(File f);


int main(void)
{
	//CopyDaysAdapter test

	/*CopyDaysAdapter cda;
	cout << cda.getDay(0) << " | " << cda.getDay(1) << " | " << cda.getDay(2) << " | " << cda.getDay(3) << " | " << cda.getDay(4) << " | " << cda.getDay(5) << " | " << cda.getDay(6) << " | " << endl;
	cda.switchDay(0); cda.switchDay(3); cda.switchDay(6);
	cout << cda.getDay(0) << " | " << cda.getDay(1) << " | " << cda.getDay(2) << " | " << cda.getDay(3) << " | " << cda.getDay(4) << " | " << cda.getDay(5) << " | " << cda.getDay(6) << " | " << endl;
	unsigned short a = cda;
	cout << cda << endl;
	system("pause");*/

	UiMaker ui = UiMaker();

	vector<File> files =
	{
		File("ASP .NET", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("C#", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("C++", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania", 1),
		File("JAVA", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania"),
		File("PRIR", "C:\\Users\\karol\\OneDrive\\Documents\\Pliki\\Szko³a\\Jêzyki Programowania", 2),
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
			File file = ui.getFile();
			File res = setFileProperties(file);

			ui.refresh();
			if (res.getCopyDate() != file.getCopyDate())
			{
				cout << "save & refresh";
			}

			
		}
		else if (key == 83) break;



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

File setFileProperties(File f)
{
	PropertiesDialog dial = PropertiesDialog(f);

	dial.show();

	while (true)
	{
		int key = KeyboardMenager::listen();

		if (key == 27) break;
		else if (key == 32) dial.select();
		else if (key == 75) dial.move(-1);
		else if (key == 77) dial.move(1);
		else if (key == 13)
		{
			f.setCopyDate(dial.getDays());
			break;
		}

	}

	return f;
}
