#ifndef DATE_H
#define DATE_H

class Invalid {	};

class Year
{
private:
	static const int MIN = 1900;
	static const int MAX = 3000;

public:
	Year(int year) : year(year) 
	{
		if ((year < MIN) || (year > MAX)) throw Invalid();
	};

	int getYear() { return year; }

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

	Date(int d, Month m, int y);
	void addDay(int days);
	int getDay() { return day; };
	Month getMonth() { return month; };
	int getYear() { return year.getYear(); };

private:
	bool check();

	int day;
	Month month;
	Year year;
};

#endif
