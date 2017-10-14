#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;




int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n = 0, m = 0;
	long avg = 0, sum = 0;
	
	cin >> n >> m;
	vector< long> bill(m + 1, 0);
	for (int i = 0; i<n; i++)
	{

		int id = 0, trans = 0;
		cin >> id >> trans;
		bill[id] += trans;
		sum += trans;

	}
	avg = sum / m;
	long extra = sum - (avg*m);
	bill[1] += extra;
	
	for (int i = 1; i <= m; i++)
	{
		bill[i] -= avg;
		cout << i << ' ' << bill[i] << endl;
	}


	return 0;
}
