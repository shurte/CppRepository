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

private:
	bool full;
	Token buffer;
};

Token get_token();
double expression();
double term();
double primary();

int main()
{
	cout << "START" << endl;



	getchar();

	return 0;
}

double expression()
{
	double left = term();
	Token token = get_token();

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
			return left;
		}

		token = get_token();
	}
}

double term()
{
	double left = primary();
	Token token = get_token();

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
				if (denominator == 0) throw new Error();
				left /= denominator;
			break;
		}
		default:
			return left;
		}

		token = get_token();
	}
}

Token get_token()
{
	char ch;

	cin >> ch;

	switch (ch)
	{
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		break;
	case '+': case '-': case '*': case '/': case '%':
		break;
	}
}