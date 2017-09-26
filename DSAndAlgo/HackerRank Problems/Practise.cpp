// Practise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

int twinArrays(vector <int> ar1, vector <int> ar2)
{
    // Complete this function
    int minNum1= INT_MAX;
int minNum2= INT_MAX;
int index1=0;
int index2=0;

int min1=2147483647;
int min2=2147483647;
int i1=0;
int i2=0;

int result =ar1[0];

for(int i=0  ;i < ar1.size(); ++i)
{
	
	if(minNum1 > ar1[i])
	{ 
		minNum2 = minNum1;
		index2 = index1;

		minNum1 = ar1[i];
		index1 = i;
	}

	else if (ar1[i] < minNum2  && index1 != i)
       {
			 minNum2 = ar1[i];
			 index2 = i;
	}
	
	if(min1 > ar2[i])
	{ 
		min2 = min1;
		i2 = i1;

		min1 = ar2[i];
		i1 = i;
	}

	else if (ar2[i] < min2  && i1 != i)
         {
			 min2 = ar2[i];
			 i2=i;
	}
	

    
}

if( i1 != index1)
	result = min1 + minNum1;
else 
	result = min(min1+minNum2,min2+minNum1);


return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar1(n);
    for(int ar1_i = 0; ar1_i < n; ar1_i++){
       cin >> ar1[ar1_i];
    }
    vector<int> ar2(n);
    for(int ar2_i = 0; ar2_i < n; ar2_i++){
       cin >> ar2[ar2_i];
    }
    int result = twinArrays(ar1, ar2);
    cout << result << endl;
    return 0;
}



