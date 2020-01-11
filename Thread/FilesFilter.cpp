#include "FilesFilter.h"

std::vector<File> FilesFilter::filterByDay(size_t day_number, std::vector<File> src)
{
	std::vector<File> res;

	for (int i = 0; i < src.size(); i++)
	{
		if (CopyDaysAdapter(src[i].getCopyDate()).getDay(day_number))
			res.push_back(src[i]);
	}

	return res;
}
