#pragma once
#include <fstream>
#include <string>
#include "File.h"
#include <vector>

class DatabaseManager
{
private:
	std::string path;

public:
	DatabaseManager(std::string p);
	void save(std::vector<File> files);
	std::vector<File> load();
};

