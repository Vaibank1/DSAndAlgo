#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool verify(const string& price)
{

	int FOUR = 0, SEVEN = 0;
	for (auto ch : price)
	{
		
		if (ch == '4')
			FOUR++;
		else if (ch == '7')
			SEVEN++;
		else
			return false;

	}
	if(FOUR == SEVEN)
		return true;

	return false;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int N(0);
	cin >> N;
	vector<pair<string, string>> laptops(N);

	for (int i = 0; i < N; i++)
	{
		cin >> laptops[i].first;
		cin >> laptops[i].second;
	}

	int index =-1;

	unsigned long long minP = LLONG_MAX ,val;
	int i = 0;
	for (auto it : laptops)
	{
		if (verify(it.second))
		{
			val = stol(it.second);
			
			if (minP > val)
			{
				index = i;
				minP = val;
			}
		}
		i++;

	}

	if (index == -1)
		cout << "-1" << endl;
	else
		cout << laptops[index].first << endl;


	return 0;
}

