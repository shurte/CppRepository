#include "date.h"
#include "quick_sort.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cout << "Chapter 9 project." << endl;

	try
	{
		const Date constDate = Date(1, Date::Month::aug, 2010);
		cout << constDate;

		Date defaultDate;
		cout << defaultDate;

		Date today(11, Date::Month::nov, 2016);
		cout << today;

		Date tommorow = today;
		tommorow.addDay(100);
		cout << tommorow;

		vector<int> vectorToSort = {4, 4, 2, 2, 4, 2};

		for (int value : vectorToSort)
		{
			cout << value << endl;
		}

		quickSort(vectorToSort, 0, vectorToSort.size() - 1);

		for (int value : vectorToSort)
		{
			cout << value << endl;
		}
	}
	catch (Invalid)
	{
		cout << "invalid date" << endl;
	}

	getchar();

	return 0;
}