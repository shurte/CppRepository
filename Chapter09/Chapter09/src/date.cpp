#include "date.h"

Date::Date(int day, Date::Month month, int year)
	: year(year)
{
	this->day = day;
	this->month = month;
	this->year = year;

	if (!check()) throw Invalid();
}

void Date::addDay(int days)
{
	this->day = this->day + days;
}

bool Date::check()
{
	if ((day < 1) || (day > 31)) return false;

	return true;
}

Date::Month intToMonth(int x)
{
	if ((x < Date::Month::jan) || (Date::Month::dec < x)) throw Invalid();

	return Date::Month(x);
}