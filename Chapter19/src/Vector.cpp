#include <Vector.h>

template<class T, class A>
void Vector<T, A>::reserve(int newAlloc) 
{
	if (newAlloc < space) return;

	T* allocatedMemory = alloc.allocate(newAlloc);

	for (int i = 0; i < getSize(); ++i)
	{
		alloc.construct(allocatedMemory + i, elements[i]);
	}

	for (int i = 0; i < getSize(); ++i)
	{
		alloc.destroy(elements + i);
	}

	alloc.deallocate(elements, space);

	elements = allocatedMemory;
	space = newAlloc;
}

template<class T, class A>
void Vector<T, A>::pushBack(const T& newValue) 
{
	if (space == 0)
	{
		reserve(8);
	}
	else if (getSize() == space)
	{
		reserve(2 * space);
	}

	alloc.construct(&elements[getSize()], newValue);
	++size;
}

template<class T, class A>
void Vector<T, A>::resize(int newSize, T val = new T())
{
	reserve(newSize);

	for (int i = getSize(); i < newSize; ++i)
	{
		alloc.construct(elements + i, val);
	}

	for (int i = newSize; i < getSize(); ++i)
	{
		alloc.destroy(elements + i);
	}

	size = newSize;
}