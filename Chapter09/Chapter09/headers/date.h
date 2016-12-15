#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Invalid {	};

class Year
{
private:
	static const int MIN = 1900;
	static const int MAX = 3000;

public:
	Year() : year(MIN) { };

	Year(int year) : year(year) 
	{
		if ((year < MIN) || (year > MAX)) throw Invalid();
	};

	int getYear() const { return year; }

private:
	int year;
};

struct Date
{
public:

	enum Month
	{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	Date();
	Date(int d, Month m, int y);

	int		getDay() const		{ return day; };
	Month	getMonth() const	{ return month; };
	int		getYear() const		{ return year.getYear(); };
	
	void	addDay(int days);
	void	addMonth(int months);
	void	addYear(int years);

private:
	bool check();

	int day;
	Month month;
	Year year;
};

int getNumberOfDays(Date::Month month, int year);
bool isDate(int, Date::Month, int);
bool leapyear(int);

bool operator == (const Date& leftDate, const Date& rightDate);
bool operator != (const Date& leftDate, const Date& rightDate);

ostream& operator << (ostream &os, const Date &date);
istream& operator >> (istream &is, Date &date);

#endif
