#include "FilesManager.h"

FilesManager::FilesManager(std::string path_to_db, std::string start_path)
	:db(DatabaseManager(path_to_db)), dm(DirManager(start_path))
{
	db_files = db.load();
}

void FilesManager::updateFile(File f)
{
	for (int i = 0; i < db_files.size(); i++)
	{
		if (db_files[i] == f)
		{
			if (f.getCopyDate() == 0) db_files.erase(db_files.begin() + i);
			else db_files[i] = f;

			db.save(db_files);
		}
	}

	if (f.getCopyDate() != 0)
	{
		db_files.push_back(f);
		db.save(db_files);
	}

}

std::vector<File> FilesManager::getFiles()
{
	std::vector<File> res = dm.getFiles();
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < db_files.size(); j++)
		{
			if (res[i] == db_files[j])
			{
				res[i] = db_files[j];
			}
		}
	}

	return res;
}

std::string FilesManager::getPath()
{
	return dm.getPath();
}

void FilesManager::setPath(std::string p)
{
	dm.setPath(p);
}

void FilesManager::moveUp()
{
	std::string res = dm.getPath();
	for (int i = res.length() - 1; i >= 0; i--)
	{
		if (res[i] == '\\')
		{
			res = res.substr(0, i);
			break;
		}
	}

	dm.setPath(res);
}


