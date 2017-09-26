#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

//#include <cstring>

using namespace std;


void  breakInt(int num , int& first , int &last)
{
	
	int digit=0;
	for(int i=0;i<6;++i)
	{
		digit = num%10;
		num/=10;
		if(i<3)
			last += digit * pow(10,i);
		else
			first += digit * pow(10,(i-3));
		
	}
	
}

int sumOfDigits(int num)
{
	int sum=0;
	int digit=0;
	for(int i=0;i<3;++i)
	{
		digit = num%10;
		num/=10;
		sum += digit;
	}
	
	return sum;
	
}

string onceInATram(int x) {
    // Complete this function
	//get the first and last sum
	
	int first=0,last=0;
	breakInt(x,first,last);
			
	//check if already equal.
	if(sumOfDigits(first) == sumOfDigits(last))
	{
		if(last == 999)
		{
			first++;		
			last=0;
		}
		else
			last++;
	}
		while(sumOfDigits(first) != sumOfDigits(last))
		{
			if(last == 999)
			{
				first++;		
				last=0;
			}
			else
				last++;
		}
	
	//merge number
	int result  =first *1000 + last;
	return std::to_string(result);
}

int main() {
  /*  int x;
    cin >> x;
    string result = onceInATram(x);
    cout << result << endl;*/

	string str;
	getline(std::cin,str,' ');


    return 0;
}
