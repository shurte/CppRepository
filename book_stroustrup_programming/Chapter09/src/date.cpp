#include "date.h"

#include <iostream>

using namespace std;

Date::Date()
{
	this->day = 1;
	this->month = Month::jan;
	this->year = Year();
}

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
	day = day + days;
	int daysInMonth = getNumberOfDays(month, year.getYear());

	while (day > daysInMonth)
	{
		day = day - daysInMonth;
		addMonth(1);
		daysInMonth = getNumberOfDays(month, year.getYear());
	}
}

void Date::addMonth(int months)
{
	int monthNumber = month + months;

	while (monthNumber > 12)
	{
		monthNumber = monthNumber - 12;
		addYear(1);
	}

	month = Month(monthNumber);
}

void Date::addYear(int years)
{
	if ((month == Month::feb) && (day == 29) && !(leapyear(year.getYear() + years)))
	{
		day = 1;
		month = Month::mar;
	}

	year = year.getYear() + years;
}

Date::Month intToMonth(int x)
{
	if ((x < Date::Month::jan) || (Date::Month::dec < x)) throw Invalid();

	return Date::Month(x);
}

bool Date::check()
{
	if ((day < 1) || (day > 31)) return false;

	return true;
}

int getNumberOfDays(Date::Month month, int year)
{
	switch (month)
	{
	case Date::jan:	case Date::mar:	case Date::may:	case Date::jul:	case Date::aug:	case Date::oct:	case Date::dec:
		return 31;
	case Date::apr:	case Date::jun:	case Date::sep:	case Date::nov:
		return 30;
	case Date::feb:
	{
		if (leapyear(year))
			return 29;
		else
			return 28;
	}
	}
	
	throw Invalid();
}

bool isDate(int day, Date::Month month, int year)
{
	if (day < 0) return false;
	if (day > getNumberOfDays(month, year)) return false;

	return true;
}

bool leapyear(int year)
{
	// We use the magic number "4" here because a leap year is every fourth year
	if ((year % 4) == 0)
		return true;
	else
		return false;
}

bool operator == (const Date& leftDate, const Date& rightDate)
{
	return ((leftDate.getDay() == rightDate.getDay())
		&& (leftDate.getMonth() == rightDate.getMonth())
		&& (leftDate.getYear() == rightDate.getYear()));
}

bool operator != (const Date& leftDate, const Date& rightDate)
{
	return !(leftDate == rightDate);
}

ostream& operator << (ostream &os, const Date &date)
{
	os << date.getYear() << " " << date.getMonth() << " " << date.getDay() << endl;

	return os;
}

istream& operator >> (istream &is, Date &date)
{
	int d;
	int m;
	int y;

	char ch1;
	char ch2;
	char ch3;
	char ch4;

	is >> ch1 >> d >> ch2 >> m >> ch3 >> y >> ch4;

	return is;
}

enum WeekDay
{
	monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

WeekDay getWeekDay(const Date &date)
{
	return monday;
}

Date nextSunday(const Date &date)
{
	return Date(date.getDay() + 7, date.getMonth(), date.getYear());
}

Date nextWeekDay(const Date &date)
{
	return Date(date.getDay() + 7, date.getMonth(), date.getYear());
}