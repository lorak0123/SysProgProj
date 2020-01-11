#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "File.h"
#include "Window.h"


class UiMaker : public Window
{
private:
	std::vector <File> files;
	std::string dir;
	int cursor;
	void drawFrame();
	void updateContent();
public:
	UiMaker(std::vector <File> f = {}, std::string d = " ");
	void updateContent(std::vector <File> f, std::string d);
	void cursorMove(int move);
	File getFile();
	void draw();
	void refresh();
};

