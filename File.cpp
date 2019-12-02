#include "File.h"

File::File(std::string name, std::string path, unsigned short date, unsigned char hour)
	:file_name(name), file_path(path), copy_date(date), copy_hour(hour)
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

unsigned char File::getCopyHour()
{
	return copy_hour;
}

void File::setCopyDate(unsigned short date)
{
	copy_date = date;
}

void File::setCopyHour(unsigned char hour)
{
	copy_hour = hour;
}
