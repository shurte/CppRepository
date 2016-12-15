#include <vector>
#include <string>

using namespace std;

void quickSort(vector<string> &vToSort, vector<int> &additionalV, const size_t beginIndex, const size_t endIndex)
{
	if (endIndex < beginIndex) return;
	if ((endIndex - beginIndex) < 2) return;

	size_t elementsNumber = (endIndex - beginIndex);
	size_t mediane = beginIndex + elementsNumber / 2;
	
	size_t l = beginIndex;
	size_t r = endIndex;

	string medianeValue = vToSort[mediane];

	while (true)
	{
		while (vToSort[l] < medianeValue)
		{
			++l;
		}

		while (vToSort[r] > medianeValue)
		{
			--r;
		}

		if (l == r)
		{
			quickSort(vToSort, additionalV, beginIndex, mediane);
			quickSort(vToSort, additionalV, mediane + 1, endIndex);
			return;
		}
		else
		{
			if (vToSort[l] > vToSort[r])
			{
				string temp = vToSort[l];
				vToSort[l] = vToSort[r];
				vToSort[r] = temp;

				int temp_int = additionalV[l];
				additionalV[l] = additionalV[r];
				additionalV[r] = temp_int;
			}

			if (vToSort[l] == vToSort[r])
			{
				if (l != mediane)
					++l;
				else if (r != mediane)
					--r;
			}
			else if (l == mediane)
			{
				mediane = r;
				medianeValue = vToSort[mediane];
			}
			else if (r == mediane)
			{
				mediane = l;
				medianeValue = vToSort[mediane];
			}

			
		}
	}
}