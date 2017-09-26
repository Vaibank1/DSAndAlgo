#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n = 0, i = 0;
	while (cin >> i)
	{
		std::cin.ignore();
		n ^= i;

	}
	cout << n;
	return 0;
}