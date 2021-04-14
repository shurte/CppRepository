#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	char ch = 'x';

	int in1 = ch;
	int in2 = 'x';

	char ch2 = in1;

	cout << ch << endl;
	cout << in1 << endl;
	cout << in2 << endl;
	cout << ch2 << endl;

	int a = 2000;
	char ch3 = a;
	int b = ch3;

	if (a != b)
		cout << "Failed!!! " << a << " != " << b << endl;
	else
		cout << "Success!!! " << a << " == " << b << endl;

	cout << ch3 << endl;

	//double d = 0.0;

	//while (cin >> d)
	//{
	//	int i = d;
	//	char ch = i;
	//	int j = ch;
	//	cout << "d=" << d << " i=" << i << " ch=" << ch << " j=" << j << endl;
	//}

	cout << "Enter addressee name:" << endl;

	string user_name;
	cin >> user_name;
	cout << "Dear " << user_name << "," << endl;
	cout << "How are you? I am fine. I miss you." << endl;

	cout << "Please enter three strings separated with a space:" << endl;
	
	string str1;
	string str2;
	string str3;

	cin >> str1 >> str2 >> str3;

	if ((str1 < str2) && (str1 < str3))
	{
		cout << str1 << " ";

		if (str2 < str3)
			cout << str2 << " " << str3;
		else
			cout << str3 << " " << str2;
	}
	else if ((str2 < str1) && (str2 < str3))
	{
		cout << str2 << " ";

		if (str1 < str3)
			cout << str1 << " " << str3;
		else
			cout << str3 << " " << str1;
	}
	else if ((str3 < str2) && (str3 < str1))
	{
		cout << str3 << " ";

		if (str1 < str2)
			cout << str1 << " " << str2;
		else
			cout << str2 << " " << str1;
	}

	cout << endl;

	string str4 = " ";
	str4 += 3;

	cout << "str4=" << str4 << endl;

	bool b1 = true;
	bool b2 = false;

	int int_bool_1 = b1;
	int int_bool_2 = b2;

	cout << "int_bool_1(true)=" << int_bool_1 << endl;
	cout << "int_bool_2(false)=" << int_bool_2 << endl;

	_getch();
}
