#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <queue>
#include <stack>


using namespace std;





int main()
{

	int arr[] = { 4, 5, 2, 25 };
	int n = sizeof(arr) / sizeof(arr[0]);
	

	stack<int> stk;
	stk.push(arr[0]);
	int cur = 0,top=0;
	for (int i = 1; i < n; ++i)
	{
		cur = arr[i];

		while (!stk.empty() )
		{
			top = stk.top();
			
			if (top < cur)
			{
				cout << top << '\t' << cur << endl;
				stk.pop();
		
			}
			else
			{				
				break;
			}
		}

		stk.push(cur);
	}

	while (!stk.empty())
	{
		cout << stk.top() << '\t' << "-1" << endl;
		stk.pop();
	}


	return 0;

}