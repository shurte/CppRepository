#pragma once

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class PunctStream {

public: 
	PunctStream(istream& is)
		: source(is), sensitive(true) { }

	void whitespace(const string& s) {
		white = s;
	}

	void addWhite(char ch) {
		white += ch;
	}

	bool isWhitespace(char ch);

	void setCaseSensitive(bool b) {
		sensitive = b;
	}

	bool isCaseSensitive() {
		return sensitive;
	}

	PunctStream& operator >> (string& s);

	operator bool();

private:
	istream& source;
	istringstream stringstream;
	string white;
	bool sensitive;
};