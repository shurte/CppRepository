#include "date.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "Chapter 9 project." << endl;

	try
	{
		Date today(11, Date::Month::nov, 2016);

		cout << today.getYear() << " " << today.getMonth() << " " << today.getDay() << endl;
	}
	catch (Invalid)
	{
		cout << "invalid date" << endl;
	}

	getchar();

	return 0;
}