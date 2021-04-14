#include <cstdio>
#include <iostream>
#include <cstdarg>
#include <initializer_list>
#include <memory>

void f(int = 7);
// void f(int = 7);
// void f(int = 8);

void g()
{
	void f(int = 9);

	f();
}

void f(int p)
{
	std::cout << p << std::endl;
}

class complex
{
	int re;
	int im;

public:
	complex(int ire = {}, int iim = {}) {}
};

void error(int severity ...)
{
	va_list ap;
	va_start(ap, severity);

	for (;;)
	{
		char* p = va_arg(ap, char*);
		if (p == nullptr) break;
		std::cerr << p << " ";
	}

	va_end(ap);

	std::cerr << "\n";
	if (severity) exit(severity);
}

void error(int severity, std::initializer_list<char*> arguments)
{
	for (auto s : arguments)
	{
		std::cerr << s << " ";
	}

	if (severity) exit(severity);
}

int main(int argument_counter, char* argument_values[])
{
	struct C { int* data; };

	std::cout << "Number of arguments: " << argument_counter << std::endl;

	for (int i = 0; i < argument_counter; ++i)
	{
		std::cout << argument_values[i] << std::endl;
	}

	// error(0, "localarg1", "localarg2", "localarg3", nullptr);
	// error(0, { "locarg1", "locarg2", "locarg3" });

	std::cout << std::endl;

	f();
	f(56);
	g();
	f();

	std::shared_ptr<int> unique_int(new int(10));

	std::cout << *unique_int << std::endl;

	int not_unique = *unique_int;

	std::cout << *unique_int << std::endl;

	std::shared_ptr<int> p1;
	std::shared_ptr<int> p2(nullptr);
	std::shared_ptr<int> p3(new int);
	std::shared_ptr<int> p4(new int, std::default_delete<int>());
	std::shared_ptr<int> p5(new int, [](int* p){delete p; }, std::allocator<int>());
	std::shared_ptr<int> p6(p5);
	std::shared_ptr<int> p7(std::move(p6));
	std::shared_ptr<int> p8(std::unique_ptr<int>(new int));
	std::shared_ptr<C> obj(new C);
	std::shared_ptr<int> p9(obj, obj->data);

	std::cout << "use_count:\n";
	std::cout << "p1: " << p1.use_count() << '\n';
	std::cout << "p2: " << p2.use_count() << '\n';
	std::cout << "p3: " << p3.use_count() << '\n';
	std::cout << "p4: " << p4.use_count() << '\n';
	std::cout << "p5: " << p5.use_count() << '\n';
	std::cout << "p6: " << p6.use_count() << '\n';
	std::cout << "p7: " << p7.use_count() << '\n';
	std::cout << "p8: " << p8.use_count() << '\n';
	std::cout << "p9: " << p9.use_count() << '\n';

	std::getchar();
	return 0;
}