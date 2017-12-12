#include<iostream>
#include<string>
#include<algorithm>



using namespace std;


int main()
{
	int N=0,K=0;
	cin >> N>>K;
	string arr;
	
	
	cin >> arr;


	int q = 0,index=0;
	for (int i = 0; i < K; i++)
	{
		cin >> q;
		if (q == 2)
		{
			cin >> index;
			index--;
				arr[index] = '1';

		}
		else
		{
			//find the length of longest sub-array consiting of only 1's

			//brute force
			int maxLen = 0, curlen = 0;
			for (int j = 0; j < N; j++)
			{
				if (arr[j] == '1')
					curlen++;
				else
				{
					maxLen = max(maxLen, curlen);
					curlen = 0;
				}
			}
			maxLen = max(maxLen, curlen);
			cout << maxLen<<endl;

		}
	}
	
	return 0;
}