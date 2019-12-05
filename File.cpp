#include "File.h"

File::File(std::string name, std::string path, unsigned short date)
	:file_name(name), file_path(path), copy_date(date)
{
}

std::string File::getName()
{
	return file_name;
}

unsigned short File::getCopyDate()
{
	return copy_date;
}


void File::setCopyDate(unsigned short date)
{
	copy_date = date;
}