#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		int N = 0, K = 0;
		cin >> N >> K;
		vector<int> friends(N);
		for (int i = 0; i<N; i++)
		{
			cin >> friends[i];
		}

		int last = N - 1;
		while (K--)
		{
			bool  DeleteFriend = false;
			for (int i = 0; i< N - 1; i++)
			{
				if (friends[i] == 102)
				{
					continue;
				}

				int j = i+1;
				while (j<N)
				{
					if (friends[j] != 102)
						break;
					j++;
				}

				if (    friends[i] < friends[j])
				{
					//delete i th friend
					friends[i] = 102;
					DeleteFriend = true;
					break;

				}
			}
			if (DeleteFriend == false)
				//delete the last friend 
			{
				friends[last] = 102;
				last--;

			}

		}

		for (int i = 0; i<N; i++)
		{
			if (friends[i] != 102)
				cout << friends[i] << " ";
		}
		cout << endl;


	}
	return 0;
}
