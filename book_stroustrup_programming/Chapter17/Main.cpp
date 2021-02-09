#include <iostream>
#include <vector>
#include <exception>

#include "List.h"

using namespace std;

class A
{
public:
	A() { cout << "constructor A()" << endl; }
	~A() { cout << "destructor ~A()" << endl; }
};

class B
{
public:
	B() : a(new A()) { cout << "constructro B()" << endl; }
	~B() { delete a; cout << "destructor ~B()" << endl; }
private:
	A* a;
};

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

	int size() const { return sz; };

	double get(int i) 
	{
		if (i >= size()) throw exception();
		return elem[i]; 
	}
	
	void set(int i, double value) 
	{ 
		if (i >= size()) throw exception(); 
		elem[i] = value; 
	}

	double operator[](int i) const
	{
		if (i >= size()) throw exception();
		return elem[i];
	}

	double& operator[](int i)
	{
		if (i >= size()) throw exception();
		return elem[i];
	}

private:
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

char * strduplicate(const char * str)
{
	int length = 0;
	while (str[length] != '\0')
		++length;

	++length;

	char * pNew = new char[length];

	for (int i = 0; i < length; ++i)
		pNew[i] = str[i];

	return pNew;
}

int main()
{
	cout << "Chapter 17." << endl;

	Vector age(4);

	cout << age.get(0) << endl;
	cout << age.get(1) << endl;
	cout << age.get(2) << endl;
	cout << age.get(3) << endl;

	try
	{
		cout << age.get(4) << endl;
	}
	catch (exception e)
	{
		cout << "Exception!!!" << endl;
	}

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

	B* b = new B;
	delete b;

	system("pause");

	delete[] pjarr;
	delete pj;

	Link * gods = insert(new Link("Tor", 0, 0), 0);
	gods = insert(new Link("Odin", 0, 0), gods);
	gods = insert(new Link("Freia", 0, 0), gods);

	Link * godsCopy = gods;

	while (gods != 0)
	{
		cout << gods->value << endl;
		gods = gods->next;
	}

	gods = godsCopy;

	while (gods != 0)
	{
		Link * god = gods;
		gods = gods->next;
		delete god;
	}

	system("pause");

	char * initialStr = "initial";

	cout << "Initial string:" << initialStr << endl;

	char * copiedStr = strduplicate(initialStr);

	cout << "Copied string:" << copiedStr << endl;

	delete[] copiedStr;

	system("pause");

	return 0;
}

void foo2()
{
	int i = 7;
	i++;
}