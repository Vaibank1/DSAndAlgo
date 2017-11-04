#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{

	

	int T = 0;
	cin >> T;
	while (T--)
	{
		int N = 0;
		unsigned long long S = 0;
		cin >> N >> S;
		vector<unsigned int>  arr(N);
		unsigned long long curDiffValue = 0,maxDiff=0;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());
		int l = 0, h = 1;
		int numOfElem = 0;
		while (l <= h && h<N) 
		{
			curDiffValue = ((unsigned long long)arr[h] - arr[l])*(h - l + 1);
			if (curDiffValue <= S)
			{
				if (numOfElem < (h - l + 1))
				{
					numOfElem = h - l + 1;
					maxDiff = curDiffValue;
				}
				else if (numOfElem == (h - l + 1))
				{
					maxDiff = max(maxDiff, curDiffValue);
				}
				h++;

			}
			else
			{
				//it means now from the index 'l' we cannot proceed further ,so increment l and try to fit index 'h'
				l++;
				while ((l<=h)&& (curDiffValue=(arr[h]-arr[l])*(h-l+1) > S))
				{
					l++;
				}			

			}
		}

		cout << numOfElem <<" "<< maxDiff;
		cout << endl;

		
	/*	int numOfElem = 0;
		for (int  i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				curDiffValue = (arr[j] - arr[i])*(j-i+1);
				if (curDiffValue <= S)
				{
					if (numOfElem < j-i+1)
					{
						maxDiff = curDiffValue;
						numOfElem = j - i + 1;

					}
				}
			}

		}

		
		cout << numOfElem << " " << maxDiff;
		cout << endl;*/
	}


	return 0;
}