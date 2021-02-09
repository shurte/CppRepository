#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

//string ExePath() {
//	char buffer[MAX_PATH];
//	GetModuleFileName(NULL, buffer, MAX_PATH);
//	string::size_type pos = string(buffer).find_last_of("\\/");
//	return string(buffer).substr(0, pos);
//}

struct Reading
{
	int hour;
	double temperature;
	Reading(int h, double t) : hour(h), temperature(t) { };
};

void chapter10_1()
{
	string fileName = ".\\data\\data.txt";

	ifstream ist(fileName.c_str());

	if (!ist)
	{
		cout << "Wrong file path!!!" << endl;

		system("pause");
		return;
	}
	else
	{
		cout << "File was found successfully!!!" << endl;
	}

	vector<Reading> fullData;
	int hour;
	double temp;

	while (ist >> hour >> temp)
	{
		Reading r(hour, temp);
		fullData.push_back(r);
	}

	for (size_t i = 0; i < fullData.size(); ++i)
	{
		cout << fullData[i].hour << " hours : " << fullData[i].temperature << " Celsium." << endl;
	}
}

void fixStream()
{
	if (cin.fail())
	{
		cin.clear();
		char ch;
		while (cin >> ch)
		{
			if (isdigit(ch))
			{
				cin.unget();
				return;
			}
		}
	}
}

void chapter10_7()
{
	while (true)
	{
		cout << "Please, enter a number:" << endl;
		int i;
		cin >> i;

		if (cin)
		{
			cout << "Successful reading" << endl;
			break;
		}
		else
		{
			cout << "Input was wrong" << endl;
			fixStream();
		}
	}
}

int main(int argn, char** argv)
{
	chapter10_7();

	system("pause");

	return 0;
}