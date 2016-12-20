#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void chapter11_2() {

	cout << "Chapter 11.2 examples:" << endl;

	cout << "general:" << "\t" << setprecision(10) << 12345.6789 << "\n"
		<< "fixed:" << "\t\t" << fixed << 12345.6789 << "\n"
		<< "scientific:" << "\t" << scientific << 12345.6789 << endl;

	cout << setw(10) << 12345 << '|' << setw(5) << 12345 << '|' << setw(3) << 12345 << '|' << endl;
}

void chapter11_3() {

	cout << "Chapter 11.3 examples:" << endl;

	string inputFileName = ".\\data\\data.txt";
	ifstream inputFileStream(inputFileName.c_str(), ios_base::binary);

	if (!inputFileStream) {
		cout << "Input stream is not correct!" << endl;
		return;
	}

	string outputFileName = ".\\data\\output.txt";
	ofstream outputFileStream(outputFileName.c_str(), ios_base::binary);

	if (!outputFileStream) {
		cout << "Output stream is not correct!" << endl;
		return;
	}

	vector<char> vectorStream;
	char ch;
	while (inputFileStream.read(&ch, 1)) {
		vectorStream.push_back(ch);
	}

	for (size_t i = 0; i < vectorStream.size(); ++i) {
		outputFileStream.write(&vectorStream[i], 1);
	}
}

void chapter11_4() {

	cout << "Chapter 11.4 examples:" << endl;

	string s = "eleven";
	istringstream strStream(s);

	double d;
	strStream >> d;

	if (!strStream)
		cout << "Reading string stream is not correct." << endl;
	else
		cout << d << endl;;
}

int main(int argc, char** argv) {

	cout << "Chapter 11." << endl;

	chapter11_2();
	chapter11_3();
	chapter11_4();

	system("pause");
	return 0;
}
