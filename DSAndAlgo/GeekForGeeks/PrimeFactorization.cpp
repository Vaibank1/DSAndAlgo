#include<iostream>
#include<vector>

using namespace std;

#define MAXN   100001


void calcSPF(vector<int>& SPF)
{

	for (int  i = 1; i < MAXN; i++)
	{
		if (i % 2 == 0)
			SPF[i] = 2;
		else
			SPF[i] = i;
	}

	for (int i = 3; i < MAXN; i++)
	{

		if (SPF[i] == i)
		{
			for (int j = i + i; j < MAXN; j += i)
				SPF[j] = i;
		}
	}

}


void primefactor(int val, vector<int>& SPF)
{

	while (val != 1)
	{
		cout << SPF[val] << " ";
		val = val / SPF[val];
	}
}



int main()
{

	int x = 13;

	vector<int> SPF(MAXN);
	calcSPF(SPF);

	primefactor(x,SPF);

	return 0;

}