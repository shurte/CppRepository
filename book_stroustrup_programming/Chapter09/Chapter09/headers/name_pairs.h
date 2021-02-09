#pragma once

#include <vector>
#include <string>

using namespace std;

class NamePairs
{
public:
	void readNames();
	void readAges();
	void printNames();
	void sort();

private:
	vector<string> names;
	vector<int> ages;
};