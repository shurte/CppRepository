#include <iostream>

using namespace std;

int (*func)(int);

int equal(int x)
{
	return x;
}

int main()
{
	cout << "Chapter 15" << endl;

	func = &equal;

	cout << func(5) << endl;

	system("pause");
	return 0;
}