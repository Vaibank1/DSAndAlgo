/*
// Sample code to perform I/O:
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	vector<int> arr(num);
	for (int i = 0; i<num; i++)
		cin >> arr[i];
	//vector<vector<int>> digitArr(10, vector<int>());
	vector<int> digitCount(10);
	//int maxDigitCount = 0;
	//int maxDigit = -1;
	for (int i = 0; i < num; i++)
	{
		int tmp = arr[0];
		vector<bool> found(10, false);
		while (tmp)
		{
			int digit = tmp % 10;
			//digitArr[digit].push_back(i);
			if (!found[digit])
			{
				digitCount[digit]++;
				found[digit] = true;
			}
			tmp /= 10;
			//maxDigitCount = max(maxDigitCount, digitCount[digit]);
			//if (maxDigitCount < digitCount[digit])
			//{
			//	maxDigitCount = digitCount[digit];
			//	//maxDigit = digit;
			//}
		}
	}

	int maxDigitCount = 0;
	for (int i = 0; i < 9; i++)
	{
		maxDigitCount = max(maxDigitCount, digitCount[i]);
	}
	cout << maxDigitCount << endl;
	
}

