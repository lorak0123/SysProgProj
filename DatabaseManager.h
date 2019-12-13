#pragma once
#include <fstream>
#include <string>

class DatabaseManager
{
private:
	std::string path;
	std::ofstream output_file;

public:
	DatabaseManager(std::string p);
};

