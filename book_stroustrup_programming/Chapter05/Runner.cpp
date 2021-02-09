#include <iostream>

#include <conio.h>

using namespace std;

void foo(double);
void foo(double);

class bad_error{};

int calc_area(int length, int width)
{
	if ((length <= 0) || (width <= 0)) throw bad_error();
	int area = length * width;
	if (area <= 0) throw bad_error();

	return area;
}

int main()
try {
	int area_1 = calc_area(1, 1003245);

	cout << area_1 << endl;

	string s("");
	string s2("");

	if (s.empty()) cout << "s is empty" << endl;
	if (s2.empty()) cout << "s2 is empty" << endl;

	if (s == s2) cout << "s and s2 are equals" << endl;

	_getch();
	return 0;
}
catch (...)
{
	cout << "exception" << endl;

	_getch();
	return 0;
}

void foo(double d)
{
	cout << d << endl;
}