#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


int main()
{

	unsigned int N = 0, Q = 0;
	cin >> N >> Q;
	int qType,q;
	vector<int> arr(N+1,0);
	//set<int> arr;
	for (unsigned int i = 0; i < Q; i++)
	{
		cin >> qType >> q;
		if (qType == 1)
		{
			arr[q] = -1;
			//arr.insert(q);
			//arr.push_back(q);
			
			
		}
		else
		{
/*
			auto index = lower_bound(arr.begin(), arr.end(), q) ;
			if (index == arr.end())
				cout << "-1" << endl;
			else
				cout << *index<<endl;*/
			

			int index = -1;
			for(int j = q;j<=N;j++)
				if (arr[j] == -1)
				{
					index = j;
					break;
					
				}

			cout << index << endl;
		}
	}

	return 0;


}