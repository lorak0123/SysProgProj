#pragma once
#include <iostream>

class File
{
private:
	std::string file_name;
	std::string file_path;
	unsigned short copy_date;
	unsigned char copy_hour;

public:
	File(std::string name, std::string path, unsigned short date = 0, unsigned char hour = 0);

	std::string getName();
	unsigned short getCopyDate();
	unsigned char getCopyHour();
	void setCopyDate(unsigned short date);
	void setCopyHour(unsigned char hour);

};

