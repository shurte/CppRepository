#include <iostream>

using namespace std;

class Error { };

class Token
{
public :
	char kind;
	double value;

	Token(char new_kind) : kind(new_kind), value(0.0) {};
	Token(char new_kind, double new_value) : kind(new_kind), value(new_value) { };
};

class TokenStream
{
public:
	TokenStream();

	Token get();
	void push_back(Token back_token);

private:
	bool full;
	Token buffer;
};

Token get_token();
double expression();
double term();
double primary();

TokenStream ts;

int main()
try {
	cout << "HI" << endl;
	double val = 0.0;

	while (cin)
	{
		Token t = ts.get();

		if (t.kind == 'q') break;

		switch (t.kind)
		{
		case ';':
			cout << "=" << val << endl;
			break;
		default:
			ts.push_back(t);
			val = expression();
			break;
		}
	}

	cout << "BY" << endl;
	getchar();

	return 0;
}
catch (Error e)
{
	cerr << "Exception!!!" << endl;
}

TokenStream::TokenStream() : full(false), buffer(0) {}

Token TokenStream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	else
		return get_token();
}

void TokenStream::push_back(Token new_buffer)
{
	if (full) throw new Error();

	buffer = new_buffer;
	full = true;
}

double expression()
{
	double left = term();
	Token token = ts.get();

	while (true)
	{
		switch (token.kind)
		{
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.push_back(token);
			return left;
		}

		token = ts.get();
	}
}

double term()
{
	double left = primary();
	Token token = ts.get();

	while (true)
	{
		switch (token.kind)
		{
		case '*':
			left *= primary();
			break;
		case '/':
			{
				double denominator = primary();
				if (denominator == 0) throw Error();
				left /= denominator;
			break;
		}
		default:
			ts.push_back(token);
			return left;
		}

		token = ts.get();
	}
}

double primary()
{
	return ts.get().value;
}

Token get_token()
{
	char ch;

	cin >> ch;

	switch (ch)
	{
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('8', val);
	}
	case ';':
	case 'q':
	case '+': case '-': case '*': case '/': case '(': case ')':
		return Token(ch);
	default:
		throw Error();
	}
}