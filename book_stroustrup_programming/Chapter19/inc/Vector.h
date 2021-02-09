#pragma once

#include <memory>

template <class T, class A = std::allocator<T> >
class Vector
{
	int size;
	T* elements;
	int space;
	A alloc;

public:

	Vector() : size(0), elements(nullptr), space(0) { };

	Vector(int i) : size(i), space(i)
	{
		elements = alloc.allocate(space);

		for (int counter = 0; counter < size; ++counter)
		{
			elements[counter] = T();
		}
	};

	Vector(const Vector&) {};

	Vector& operator=(const Vector&) {};

	~Vector() 
	{
		alloc.deallocate(elements, space);
	};

	T& operator[](int i) { return elements[i]; };
	const T& operator[](int i) const { return elements[i]; };

	int getSize() { return size; };
	int capasity() { return space; };

	void resize(int newSize, T = new T());
	void pushBack(const T& newValue);
	void reserve(int newAlloc);
};
