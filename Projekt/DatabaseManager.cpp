#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(std::string p)
	:path(p)
{
}

void DatabaseManager::save(std::vector<File> files)
{
	if (files.size() > 0)
	{
		std::ofstream output_file;

		output_file.open(path);

		for (int i = 0; i < files.size(); i++)
		{
			output_file << files[i].getPath() + "\n" + files[i].getName() + "\n" << (char)files[i].getCopyDate() << '\n' << files[i].isDir() << '\n';
		}

		output_file.close();
	}
}

std::vector<File> DatabaseManager::load()
{
	std::vector<File> res;

	std::ifstream file;

	file.open(path);

	std::string file_str[4];
	while (std::getline(file, file_str[0]))
	{
		std::getline(file, file_str[1]);
		std::getline(file, file_str[2]);
		std::getline(file, file_str[3]);

		res.push_back(File(file_str[1], file_str[0], ((file_str[3] == "0")? false : true), (unsigned char)file_str[2][0]));
	}

	return res;

}
