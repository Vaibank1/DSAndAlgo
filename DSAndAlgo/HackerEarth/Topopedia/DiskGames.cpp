#include<iostream>
#include<vector>
#include<string>


using namespace std;


int main()
{
	
	unsigned long M = 0;
	int T = 0;
	cin >> T;
	while (T--)
	{
		cin >> M;
		if (M == 1 || M == 3 || M == 0)
		{
			cout << "RK" << endl;
			continue;
		}
		else if (M == 2)
		{
			cout << "Nakul"<<endl;
			continue;
		}

		M = M % 4;
		if (M == 0 || M == 2 )
			cout << "RK"<<endl;
		else
			cout << "Nakul"<<endl;

	}

	return 0;
}