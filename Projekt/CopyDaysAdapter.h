#pragma once
class CopyDaysAdapter
{
private:
	unsigned short days;
public:
	CopyDaysAdapter(unsigned short d = 0);
	void switchDay(size_t day_number);
	bool getDay(size_t day_number);
	operator unsigned short();
};

