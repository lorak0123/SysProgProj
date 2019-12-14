#pragma once
#include <vector>
#include "File.h"
#include "DatabaseManager.h"
#include "DirManager.h"
#include <string>

class FilesManager
{
private:
	std::vector<File> db_files;
	DatabaseManager db;
	DirManager dm;
public:
	FilesManager(std::string path_to_db = "C:\\", std::string start_path = "C:\\");
	void updateFile(File f);
	std::vector<File> getFiles();
	std::string getPath();
	void setPath(std::string p);
	void moveUp();
};

