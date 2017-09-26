
#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

#define MAX 15
int main()
{
	int arr[10];

	for(int i=0; i< MAX; ++i)
	{
		arr[i] =  rand() % 10 - 5;
	}

	int max_so_far = arr[0];
   int curr_max = arr[0];
 //solution which handles all negative numbers
   for (int i = 1; i < MAX; i++)
   {
        curr_max = max(arr[i], curr_max+arr[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   
   //solution which do not handle all negative numbers
	int curMax=arr[0],maxGlobal =0,s=0;
	int indexStart=0,indexEnd=0;
	for (int i = 1; i < MAX; i++)
	{
		curMax= curMax+arr[i];
	
		if(maxGlobal < curMax)
		{
			maxGlobal = curMax;
			indexStart =s;
			indexEnd=i;

		}

		if(curMax <0)
		{
			curMax=0;
			s= i+1;
		}


	}

	_getch();
	return 0;
}