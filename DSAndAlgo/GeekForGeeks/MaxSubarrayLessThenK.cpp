#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <queue>


using namespace std;





int main()
{

	int arr[]={ 1,5,3,6,1,2,3,4} ;
	int k=11;

	int N= sizeof(arr)/sizeof(arr[0]);

	/*for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand()%7 +1 + rand()%11;

	}*/

	int l=0,r=0;
	int sum =0;
	int maxLn=0,endIndex=0;
	while(l<=r  && r<N)
	{
		if(sum + arr[r] < k)
		{
			//include this element in subarry
			sum +=arr[r];
			endIndex = r;
			
		}
		else 
		{
			//current elemet exceeds k
			//store the last sub-array
			endIndex = r-1;
			maxLn = max(maxLn,endIndex-l+1);
			
			//if current element is greater then or equal to k, then no subarray can include this element.
			//hence search in next elements
			if(arr[r] >= k)
			{
				l=r+1;
				sum=0;
				

			}
			else 
			{
				//check whether we can increase the subarray size by excluding elements from the start			
				sum+=arr[r];
				while (l<=r && sum >=k)
				{
					//increment the start index  to see whether from here we can get max subarray.					
					sum -= arr[l];
					l++;					
				}
				

			}

			
			
		}
		r++;
		
	
	}


	maxLn = max(maxLn,endIndex-l+1);

	cout<<maxLn<<endl<<l<<'\t'<<endIndex;

return 0;
}