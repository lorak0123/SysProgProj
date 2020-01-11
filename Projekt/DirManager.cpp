#include "DirManager.h"

DirManager::DirManager(std::string p)
	:path(p)
{
}

std::string DirManager::getPath()
{
	return path;
}

std::vector<File> DirManager::getFiles()
{
	std::vector<File> res;

	try {
		for (const auto& entry : std::filesystem::directory_iterator(path))
			res.push_back(File(entry.path().filename().string(), path, entry.is_directory(), 0));
	}
	catch (std::system_error x)
	{
		//std::cout << x.what() << std::endl;
		//system("pause");
	}
	
	return res;
}

void DirManager::setPath(std::string p)
{
	path = p;
}
