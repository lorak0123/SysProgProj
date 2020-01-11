#include "File.h"

File::File(std::string name, std::string path, bool id, unsigned short date)
	:file_name(name), file_path(path), copy_date(date), is_dir(id)
{
}

std::string File::getName()
{
	return file_name;
}

std::string File::getPath()
{
	return file_path;
}

unsigned short File::getCopyDate()
{
	return copy_date;
}


void File::setCopyDate(unsigned short date)
{
	copy_date = date;
}

bool File::isDir()
{
	return is_dir;
}

bool File::operator==(const File& f) const
{
	if (file_name == f.file_name && file_path == f.file_path)
		return true;
	else
		return false;
}
