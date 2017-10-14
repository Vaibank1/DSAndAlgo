#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
#include<iostream>
#include<bitset>
using namespace std;

int main()
{

	int T = 0;
	cin >> T;

	bitset<200001> bset;

	while (T--)
	{
		 int n = 0;
		 int k = 0,s=0;
		cin >> n >> k;
		for(int i=0;i<n;i++)
		{
			cin >> s;
			bset[s] = 1;
		}

		int i = 0;
		if (k != 0)
		{
			for (i = 0; i < bset.size(); i++)
			{
				if (bset[i] == 0)
				{
					k--;
					bset[i] = 1;
					if (k == 0)
						break;
				}

			}
			
		}
		int mex = 0;
		for (i; i < bset.size(); i++)
		{
			if (bset[i] == 0)
				break;
		}
		cout << i << endl;
		bset.reset();


	}

	return 0;
}	