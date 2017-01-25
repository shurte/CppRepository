#include <iostream>
#include <vector>

using namespace std;

class Vector
{
public:
	Vector(int size): sz(size), elem(new double[size]) 
	{
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = 0;
		}
	};

	~Vector()
	{
		delete[] elem;
	};

	int size() { return sz; };

// private:
	int sz;
	double* elem;

};

void foo()
{
	int i = 0;
	i++;
}

int globalI = 98;

void foo2();

int main()
{
	cout << "Chapter 17." << endl;

	Vector age(4);

	cout << age.elem[0] << endl;
	cout << age.elem[1] << endl;
	cout << age.elem[2] << endl;
	cout << age.elem[3] << endl;

	char ch = 'c';
	char* pch = &ch;
	int i = 5;
	int* pi = &i;

	cout << pch << " points to " << *pch << endl;
	cout << pi << " points to " << *pi << endl;

	cout << "char size " << sizeof(char) << " " << sizeof('c') << endl;
	cout << "int size " << sizeof(int) << " " << sizeof(2 + 2) << endl;
	cout << "double size " << sizeof(double) << " " << sizeof(4.3) << endl;
	cout << "float size " << sizeof(float) << " " << sizeof(4.3f) << endl;
	cout << "vector<int> size " << sizeof(vector<int>) << endl;
	cout << "vector<double> size " << sizeof(vector<double>) << endl;

	vector<int> v(1000);
	cout << "vector<int> with 1000 elements size " << sizeof(v) << endl;
	cout << "pointer size " << sizeof(char*) << " " << sizeof(pi) << endl;
	
	cout << "local variable adress " << &i << endl;
	cout << "global variable adress " << &globalI << endl;
	cout << "main adress " << &main << endl;
	cout << "foo adress " << foo << endl;
	cout << "foo2 adress " << foo2 << endl;

	int* pj = new int;
	int* pjarr = new int[3];

	cout << "pj in heap value " << pj << endl;
	cout << "pj adress " << &pj << endl;
	cout << "pjarr in heap value " << pjarr << endl;
	cout << "pjarr adress " << &pjarr << endl;

	// pj = pjarr;

	system("pause");

	delete[] pjarr;
	delete pj;

	return 0;
}

void foo2()
{
	int i = 7;
	i++;
}