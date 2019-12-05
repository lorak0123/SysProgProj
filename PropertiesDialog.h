#pragma once
#include <iostream>
#include "File.h"
#include <windows.h>
#include "Window.h"
#include "CopyDaysAdapter.h"

class PropertiesDialog : public Window
{
private:
	File file;
	short cursor;
	CopyDaysAdapter days_adapter;
	void updateContent();
public:
	PropertiesDialog(File f);
	unsigned short getDays();
	void select();
	void move(int move);
	void show();
};

