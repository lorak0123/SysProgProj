#include <filesystem>
#include <iostream>
#include <windows.h>
#include <vector>
#include <chrono>
#include <ctime>
#include <string>
#include <future>
#include "FilesFilter.h"
#include "../Projekt/File.h"
#include "../Projekt/DatabaseManager.h"




using namespace std;



bool dirExists(const std::string& dirName_in);
void makeCopy(string file_name, string target);

int main()
{
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

	DatabaseManager db = DatabaseManager("C:\\Users\\karol\\Wnek\\config.txt");
	vector<File> files = db.load();

	int weekday = ((timenow / 86400) - 4) % 7;


	for (int i = 0; i < files.size(); i++)
		cout << files[i].getPath() << files[i].getName() << endl;


	
	cout << "weekday = " << weekday << endl;


	files = FilesFilter::filterByDay(weekday, files);

	for (int i = 0; i < files.size(); i++)
	{
		if (!dirExists(files[i].getPath() + "archives"))
			filesystem::create_directories(files[i].getPath() + "archives");

		string target_dir = files[i].getPath() + "archives\\" + files[i].getName() + to_string(timenow / 86400);

		if (!dirExists(target_dir))
		{
			filesystem::create_directories(target_dir);

			future<void> fut = async(makeCopy, files[i].getPath() + files[i].getName(), target_dir);

			cout << files[i].getName() <<" done\n";

			//filesystem::copy(files[i].getPath() + files[i].getName(), target_dir, std::filesystem::copy_options::recursive);

		}
	}
		
	 

	return 0;

	
}


bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

void makeCopy(string file_name, string target)
{
	filesystem::copy(file_name, target, std::filesystem::copy_options::recursive);
}
