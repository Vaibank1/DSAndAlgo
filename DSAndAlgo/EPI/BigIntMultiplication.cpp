#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <vector>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>

using namespace std;

class BigInt
{
	int sign;
	vector<int> num;
public:
	BigInt() :sign(1) {}
	BigInt(string str)
	{
		sign = str[0] == -1 ? -1 : 1;
		for (size_t i = str[0] == -1?1:0; i < str.length(); i++)
		{
			num.push_back(str[i]-'0');

		}
	}

	BigInt operator*(const BigInt& num2)
	{
		BigInt result;
		result.sign = this->sign * num2.sign;
		
		
		string tmp;
		


	}
};

//int main()
//{
//
//
//
//	return 0;
//}