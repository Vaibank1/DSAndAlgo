#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

typedef unsigned long long ULL;

bool cmp(const pair<int, int>& a, const pair<int, int>&b)
{
	
	return a.first<b.first ;

}


int main()
{
	int N = 0;
	cin >> N;
	ULL limit = (10 ^ 9) + 1;
	vector<pair<int,int>> cord(N);
	//ULL tmp = 0;
	for (int i = 0; i < N; i++)
	{
		/*cin >> tmp;
		cin >> cord[tmp];*/
		cin >> cord[i].first >> cord[i].second;
		
	}

	int d, p;
	cin >> d >> p;
	//cord[d] = p;
	
	if (p >= d)
	{
		cout << '0';
	}
	else
	{
		
		
		int minCount = 0;
		sort(cord.begin(), cord.end(), cmp);
		bool isFound = false;
		int curPos = d;
		int curFuel = p;
		int index = N - 1;
		int loop = N;

		for (int i = N-1; i >=0; i--)
		{
			if (curPos - curFuel  <= 0)
			{
				//enough fuel to reach destination
				isFound = true;
				break;
			}

			int status = curFuel -(curPos- cord[i].first);
			//enough fuel
			if (status > 0)
				continue;
			//fuel empty
			else if (status == 0)
			{
				//refill at this station
				curFuel = cord[i].second;
				curPos = cord[i ].first;

			}

			else
			{
				//car would not reach here, need to refuel at previous station
				if (i + 1 >= N )
				{
					//invalid
					break;
				}				
				curFuel += cord[i + 1].second;
				curFuel -= curPos - cord[i+1].first;
				curPos = cord[i+1].first;

			}
			minCount++;

		}

		if (isFound || (curPos - curFuel <= 0))
			cout << minCount;
		else
			cout << "-1";

		//while (loop--)
		//{
		//	int posOutOFGas = curPos-curFuel;
		//	if (posOutOFGas > 0)
		//	{
		//		//closet gas station
		//		/*int closetStation = upper_bound(cord.begin(), cord.end(), make_pair(posOutOFGas, 0), cmp) - cord.begin();
		//		if (closetStation != 0)
		//		{
		//			if (cord[closetStation - 1].first == posOutOFGas)
		//				closetStation--;
		//		}
		//		if (cord[closetStation].first)
		//		{
		//		}*/


		//		int closetStation = -1;
		//		for (int i = index; i >=0; i--)
		//		{
		//			if (posOutOFGas <= cord[i].first)
		//				closetStation = i;
		//		}
		//		if (closetStation == -1)
		//			break;
		//		curFuel = ( curFuel- (curPos - cord[closetStation].first) ) + cord[closetStation].second;
		//		curPos = cord[closetStation].first;
		//		minCount++;
		//		index = closetStation-1;

		//	}
		//	else
		//	{
		//		isFound = true;
		//		break;
		//	}
			
		}

		


		/*vector<bool> visited(N, false);
		int loop = N;
		int curRange = p;
		int mx = 0,index=0;
		while (N--)
		{

			mx = 0;
			for (int i = index+1; i < N; i++)
			{
				if (!visited[i] &&  cord[i].first <= curRange)
				{
					if (mx < cord[i].second)
					{
						mx = cord[i].second;
						index = i;
					}
				}
				
			}

			visited[index] = true;

			curRange += mx;
			minCount++;
			if (curRange >= d)
			{
				cout << minCount;
				return 0;
			}
	
		}*/
		


	


	return 0;
}
