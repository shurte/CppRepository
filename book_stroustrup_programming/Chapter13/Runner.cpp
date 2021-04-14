#include <iostream>
#include <utility>

using size_type = unsigned int;

template<class T, class A = Allocator<T>>
class vector
{
private:
	T* elem;
	T* space;
	T* last;
	A alloc;

public:

	explicit vector(size_type n, const T& = T(), const A& = A());

	vector(const vector& v);
	vector& operator=(const vector& v);

	vector(vector&& v);
	vector& operator=(vector&& v);

	~vector();

	size_type size() { return (space - elem); }
	size_type capacity() { return (last - elem); }
	void reserve(size_type n);
	void resize(size_type n, const T& = {});
	void push_back(const T&);
};

template<class T, class A>
vector<T, A>::vector(size_type n, const T& val, const A& a) : alloc(a)
{
	elem = alloc.allocate(n);
	
	iterator p;

	try
	{
		iterator end = elem + n;
		for (p = elem; p != last; ++p)
		{
			a.construct(p, val);
		}
		last = space = p;
	}
	catch (...)
	{
		for (iterator q = elem; q != p; ++q)
		{
			alloc.destroy(q);
		}

		alloc.deallocate(elem, n);
		throw;
	}
}

class A
{
public:
	int a_i;
	A() { a_i = 1; std::cout << "A constructor" << std::endl; }
	A(const A& a) { a_i = a.a_i; std::cout << "A copy constructor" << std::endl; }
	A(A&& a) { a_i = a.a_i; a.a_i = 0; std::cout << "A move constructor" << std::endl; }

	~A() { a_i = 0; std::cout << "A destructor" << std::endl; }

	void fooA() { std::cout << "A foo() " << "i: " << a_i << std::endl; }
};

A foo(A a) { A aa; return aa/*std::move(aa)*/; }

int main(int argc, char** argv)
{
	//int* i = new int{5};
	//std::cout << "i: " << *i << std::endl;
	//int* j = new int{ std::move(*i) };
	//std::cout << "i: " << *i << std::endl;
	//std::cout << "j: " << *j << std::endl;
	//delete i;
	//std::cout << "i: " << *i << std::endl;
	//std::cout << "j: " << *j << std::endl;
	//getchar();

	A a;
	A aa = foo(a);
	aa.a_i = 15;
	A aaa = std::move(aa);
	aaa.a_i = 24;

	std::cout << "a.a_i:  " << a.a_i << std::endl;
	std::cout << "aa.a_i: " << aa.a_i << std::endl;
	std::cout << "aaa.a_i: " << aaa.a_i << std::endl;

	getchar();

	return 0;
}