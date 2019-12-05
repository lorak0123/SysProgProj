#pragma once
#include <iostream>

class File
{
private:
	std::string file_name;
	std::string file_path;
	unsigned short copy_date; // 8 bits for 7 days status

public:
	File(std::string name, std::string path, unsigned short date = 0);

	std::string getName();
	unsigned short getCopyDate();
	void setCopyDate(unsigned short date);

};

