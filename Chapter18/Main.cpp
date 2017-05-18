#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct X
{
	int val;

	void out(const string& str)
	{
		cerr << this << "->" << str << ": " << val << endl;
	}

	X() { out("X()"); val = 0; out("X()"); };
	X(int i) { out("X(int)"); val = i; out("X(int)"); };
	X(const X& x) { out("X(X&)"); val = x.val; out("X(X&)"); };

	X& operator=(const X& x) { out("operator="); val = x.val; out("operator="); return *this; };
	~X() { out("~X()");  };
};

X glob(2);

X copy(X a) { return a; };

X copy2(X a) { X aa = a; return aa; };

X& ref_to(X& a) { return a; };

X* make(int i) { X a(i); return new X(a); };

struct XX { X a; X b; };

struct ArrayStr
{
	char* chArray;

	ArrayStr(char iChArray[])
	{
		chArray = iChArray;
	}
};

void chapter18_1()
{

}

int main()
{
	cout << "Chapter 18." << endl;

	X loc(4);
	X loc2 = loc;

	cout << endl << endl;

	loc = X(5);
	loc2 = copy(loc);
	loc2 = copy2(loc);

	cout << endl << endl;

	X loc3(6);
	X& r = ref_to(loc);

	cout << endl << endl;

	delete make(7);
	delete make(8);

	cout << endl << endl;

	vector<X> v(4);
	XX loc4;

	cout << endl << endl;

	X* p = new X(9);
	delete p;

	cout << endl << endl;

	X* pp = new X[5];
	delete[] pp;

	cout << endl << endl;

	system("pause");

	return 0;
}