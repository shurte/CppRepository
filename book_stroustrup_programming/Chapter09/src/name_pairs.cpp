#include "name_pairs.h"
#include "quick_sort.h"

#include <iostream>

void NamePairs::readAges()
{
	cout << "Input ages for people:" << endl;

	for (size_t i = 0; i < names.size(); ++i)
	{
		cout << "Input ages for " << names[i] << endl;
		int age;
		cin >> age;
		ages.push_back(age);
	}

	cout << endl;
}

void NamePairs::readNames()
{
	cout << "Input names (type \"end\" for exit input):" << endl;

	while (cin)
	{
		string name;
		cin >> name;

		if (name == "end") return;

		names.push_back(name);
	}
}

void NamePairs::printNames()
{
	for (size_t i = 0; i < names.size(); ++i)
	{
		cout << names[i] << " ";

		if (i < ages.size())
		{
			cout << ages[i] << " ages.";
		}

		cout << endl;
	}
}

void NamePairs::sort()
{
	quickSort(names, ages, 0, names.size() - 1);
}