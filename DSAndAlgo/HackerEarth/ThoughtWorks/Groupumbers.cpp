#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	int T = 0;

	cin >> T;

	while (T--)
	{

		int N = 0;
		cin >> N;
		unordered_map<int,int> arr;
		int key = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> key;
			arr[key]++;
		}

		bool isValid = true;
		int numOfCountries = 0;
		for (auto it : arr)
		{

			if (it.second%it.first != 0)
			{
				isValid = false;
				break;
			}
			numOfCountries += it.second / it.first;
		}

		if(isValid)
			cout << numOfCountries; 
		else
		cout<< "Invalid Data";

		cout << endl;
			

	}


}	