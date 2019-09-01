#include<iostream>
#include<set>



using namespace std;



int main()
{

	int N,Q;
	cin >> N>>Q;
	set<int> countZeroes,countOnes;
	for (int i = 1; i <= N; i++)
	{
		countOnes.insert(i);
	}
	while (Q--)
	{
		
		int queryType, index;
		cin >> queryType >> index;

		if (queryType == 0)
		{
			countZeroes.insert(index);
			countOnes.erase(index);
		}
		else
		{
			if (index > N - countZeroes.size())
				cout << "-1" << endl;

			else if (countZeroes.size() < countOnes.size())
			{
				//check the number of zeroes less then the given index
				int count = 0;
				for (auto it : countZeroes)
				{
					if (it <= index)
						count++;
					else  break;

				}

				cout << index + count << endl;

			}
			else
			{
				int count = 0;
				for (auto it : countOnes)
				{
					if (it <= index)
						count++;
					else  break;

				}
				cout << count << endl;
			}

		}


	}

	return 0;

}