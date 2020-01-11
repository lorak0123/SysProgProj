#pragma once
#include <iostream>
#include <vector>
#include "../Projekt/File.h"
#include "../Projekt/CopyDaysAdapter.h"

class FilesFilter
{
public:
	static std::vector<File> filterByDay(size_t day_number, std::vector<File> src);
};

