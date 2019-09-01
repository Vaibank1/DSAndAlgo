
#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>

#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
using namespace std;





int main() {
	
	int n, value;
	
	cin >> n;
	vector<int> A(n);

	int numOfBuckets = n / 999 +1;
	int curBucket = 0;
	vector<int> minOfBuckets(numOfBuckets,INT_MAX);
	int globalMin = INT_MAX;
	int count = 0;
	for (int A_i = 0; A_i < n; A_i++) {
		
		cin >> value;
		A[A_i] = value;
		count++;
		if (count == 1000)
		{
			count = 1;
			curBucket++;
		}
		minOfBuckets[curBucket] = min(minOfBuckets[curBucket],value );
		globalMin= min(globalMin, value);		
	}

	
	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++) {
		int xi;
		cin >> xi;
		bool found = false;
		if (xi < globalMin)
			cout << "-1" << endl;
		else
		{
			//determine which bucket
			for (int i = numOfBuckets-1; i >= 0; i++)
			{
				if (xi >= minOfBuckets[i])
				{
					int startOfBucket= i*1000;
					int endOfBucket = startOfBucket + 999;
					endOfBucket = min(endOfBucket,(int) A.size() - 1);
					for (int j = endOfBucket; j >= startOfBucket; j--)
					{
						if (xi >= A[j])
						{
							cout << j+1 << endl;
							found = true;
							break;
						}
					}
					if (found)
						break;


				}
			}
		}
	
		
	}
	return 0;
}
