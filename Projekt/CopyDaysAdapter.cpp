#include "CopyDaysAdapter.h"

CopyDaysAdapter::CopyDaysAdapter(unsigned short d)
	:days(d)
{
}

void CopyDaysAdapter::switchDay(size_t day_number)
{
	days ^= 1 << day_number;
}

bool CopyDaysAdapter::getDay(size_t day_number)
{
	return (days >> day_number) & 1;
}


CopyDaysAdapter::operator unsigned short()
{
	return days;
}
