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

	for (auto& entry : std::filesystem::directory_iterator(path))
		res.push_back(File(entry.path().filename().string(), path, 0));
	
	return res;
}
