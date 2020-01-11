#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include "File.h"


class DirManager
{
private:
	std::string path;
public:
	DirManager(std::string p = "C:\\");
	std::string getPath();
	std::vector<File> getFiles();
	void setPath(std::string p);
};

