
#include "stdafx.h"
#include <iostream>
#include <vector>

#include <conio.h>
#include <math.h>
#include <string>
using namespace std;

int main()
{


	int x=4321;
	int y=3214;
	int sum=0;
	while(x !=0)
	{
		int a = x%10;
		int b = y%10;
		int z = abs(b-a);
		x/=10;
		y/=10;
		sum+=z;

	}
	cout<<sum;
	return 0;
}