
#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>
#include<array>
using namespace std;

//find the max index diff where A[i]!=A[j]

int main()
{
	
	array<int, 100> arr;
	for (auto &a : arr)
	{
		a = rand() % 1000 + 1;
	}


	int i = 0, j = arr.size() - 1;
	int diff = 0;
	int sign = -1;
	while (i < j)
	{
		if (arr[i] != arr[j])
		{
			diff = j - i;
			break;
		}
		if (sign == 1)
		{
			i++;
		}
		else
			j--;
		sign *= -1;

	}

	cout << "j= " << j << "  i = " << i;

	return 0;
}