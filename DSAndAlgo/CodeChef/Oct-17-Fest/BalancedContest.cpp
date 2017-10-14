#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
#include<iostream>

using namespace std;

int main()
{

	int T=0;
	cin >> T;
	
	
	while (T--)
	{
		int numOfProb = 0, numOfParticipants = 0, solvedParticipant = 0, cakeWalkNum = 0, hardNum = 0;
		cin >> numOfProb >> numOfParticipants;
		
		int numOfCakeWalkPrb = 0,numOfHardProb=0;
		cakeWalkNum = numOfParticipants / 2;
		hardNum = numOfParticipants / 10;
		while (numOfProb--)
		{
			
			cin >> solvedParticipant;
			if (solvedParticipant <= hardNum)
				numOfHardProb++;
			else if(solvedParticipant >= cakeWalkNum)
			{
				numOfCakeWalkPrb++;
			}

		}
		if (numOfCakeWalkPrb == 1 && numOfHardProb == 2)
			cout << "yes"<<endl;
		else
			cout << "no\n";
	}

return 0;
}