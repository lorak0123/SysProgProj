#pragma once
#include <iostream>

class File
{
private:
	std::string file_name;
	std::string file_path;
	bool is_dir;
	unsigned short copy_date; // 8 bits for 7 days status

public:
	File(std::string name, std::string path, bool id = false, unsigned short date = 0);

	std::string getName();
	std::string getPath();
	unsigned short getCopyDate();
	void setCopyDate(unsigned short date);
	bool isDir();
	bool operator ==(const File& f) const;

};

