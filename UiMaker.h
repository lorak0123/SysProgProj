#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "File.h"


class UiMaker
{
private:
	std::vector <File> files;
	std::string dir;
	int cursor;
	int maxx;
	int maxy;
	void drawFrame();
	void updateContent();
	void updateRange();
	void setCursor(int x, int y);
	void getCursor(int* x, int* y);
public:
	UiMaker(std::vector <File> f = {}, std::string d = " ");
	bool sizeChanges();
	void updateContent(std::vector <File> f, std::string d);
	void cursorMove(int move);
	void clearScreen();
	File getFile();
	void draw();
	void refresh();
	void getRange(int* x, int* y);
};

