#include <Vector.h>

#include <iostream>
#include <vector>

int main()
{
	Vector<double> v1(3);

	for (int i = 0; i < v1.getSize(); ++i)
	{
		std::cout << v1[i] << " ";
	}

	std::system("pause");

	return 0;
}