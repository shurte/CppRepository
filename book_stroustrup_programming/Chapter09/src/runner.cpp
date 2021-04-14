#include "date.h"
#include "quick_sort.h"
#include "name_pairs.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(const vector<string> &vToPrint, const string &title)
{
	cout << title << endl;
	for (string value : vToPrint)
	{
		cout << value << endl;
	}
}

int main()
{
	cout << "Chapter 9 project." << endl;

	try
	{
		Date today(11, Date::Month::nov, 2016);
		cout << today;

		//vector<string> vectorToSort = { "a", "b", "asdf", "werthd", "asdyhe", "eryujj"};
		//printVector(vectorToSort, "Unordered vector:");
		//quickSort(vectorToSort, 0, vectorToSort.size() - 1);
		//printVector(vectorToSort, "Ordered vector:");

		NamePairs namePairs;
		namePairs.readNames();
		namePairs.readAges();
		cout << "Unordered:" << endl;
		namePairs.printNames();
		namePairs.sort();
		cout << "Ordered:" << endl;
		namePairs.printNames();
	}
	catch (Invalid)
	{
		cout << "invalid date" << endl;
	}

	getchar();
	getchar();

	return 0;
}