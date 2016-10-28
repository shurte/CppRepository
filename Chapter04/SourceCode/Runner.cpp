#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <stdio.h>
#include <conio.h>

using namespace std;

int two_powers();

int main()
{
	//printf("Hi guys!\n");

	//char ch_a = 'a';
	//char ch_z = 'z';

	//for (char i = ch_a; i <= ch_z; ++i)
	//{
	//	cout << i << "=" << (int)i << endl;
	//}

	//for (char i = 'A'; i <= 'Z'; ++i)
	//{
	//	cout << i << "=" << (int)i << endl;
	//}

	//for (char i = '0'; i <= '9'; ++i)
	//{
	//	cout << i << "=" << (int)i << endl;
	//}

	//double d_min = DBL_MAX;
	//double d_max = DBL_MIN;
	//double d_cur = 0;
	//double d_sum = 0;
	//string unit = "";

	//vector<double> d_vector;

	//cout << "Enter double value and units(cm, in, ft or m):" << endl;

	//while (cin >> d_cur >> unit)
	//{
	//	cout << "Entered value is " << d_cur << endl;

	//	double d_in_meters = 0;

	//	if (unit == "cm") 
	//	{
	//		d_in_meters = d_cur / 100;
	//	}
	//	else if (unit == "in")
	//	{
	//		d_in_meters = 2.54 * d_cur / 100;
	//	}
	//	else if (unit == "ft")
	//	{
	//		d_in_meters = 12 * 2.54 * d_cur / 100;
	//	}
	//	else if (unit == "m")
	//	{
	//		d_in_meters = d_cur;
	//	}
	//	else
	//	{
	//		cout << "Unit is unknown!!!" << endl;
	//		continue;
	//	}

	//	cout << "The length is " << d_in_meters << " m." << endl;
	//	d_vector.push_back(d_in_meters);

	//	if (d_min > d_in_meters)
	//	{
	//		d_min = d_in_meters;
	//		cout << "The least value is " << d_min << endl;
	//	}

	//	if (d_max < d_in_meters)
	//	{
	//		d_max = d_in_meters;
	//		cout << "The most value is " << d_max << endl;
	//	}

	//	d_sum += d_in_meters;

	//	cout << "The sum length is " << d_sum << " m." << endl;
	//}

	//sort(d_vector.begin(), d_vector.end());
	//cout << "Entered values are:" << endl;

	//for (int i = 0; i < d_vector.size(); ++i)
	//{
	//	cout << d_vector[i] << " m." << endl;
	//}

	//cout << "The least value is " << d_min << endl;
	//cout << "The most value is " << d_max << endl;
	//cout << "The sum length is " << d_sum << " m." << endl;

	//string str;
	//cin >> str;

	//vector<double> d_vector_2;
	//double d_cur_2 = 0;

	//while (cin >> d_cur_2)
	//	d_vector_2.push_back(d_cur_2);

	//sort(d_vector_2.begin(), d_vector_2.end());

	//if ((d_vector_2.size() % 2) == 0)
	//{
	//	cout << "Mediane is " << (d_vector_2[d_vector_2.size() / 2] + d_vector_2[d_vector_2.size() / 2 + 1]) / 2 << endl;
	//}
	//else
	//{
	//	cout << "Mediane is " << d_vector_2[d_vector_2.size() / 2 + 1] << endl;
	//}

	//_getch();

	return two_powers();
}

int two_powers()
{
	__int64 res = 1;

	for (int i = 0; i < 65; ++i)
	{
		if (i == 0)
			cout << "2 power 0 == 1" << endl;
		else
			cout << "2 power " << i << " == " << res << endl;

		res *= 2;
	}

	_getch();

	return 0;
}