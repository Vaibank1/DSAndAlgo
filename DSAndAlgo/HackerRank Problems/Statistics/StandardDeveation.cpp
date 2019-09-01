#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


double findMedian(vector<int>&arr, int start, int end)
{
	int N = end - start;
	double median = 0;
	if (N % 2)
	{
		median = arr[start + N / 2];
	}
	else
	{
		median = arr[start + N / 2] + arr[start + N / 2 - 1];
		median /= 2.0;
	}

	return median;

}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N = 0;
	cin >> N;
	vector<int> num(N);
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		sum += num[i];
	}
	double mean = double(sum) / (N);
	sum = 0;
	for (int i = 0; i < N; i++)
	{	
		sum+= pow(abs(num[i]- mean),2);
	}
	
	double deviation = 0.0;
	deviation = (double)sum / (double)N;
	deviation = sqrt(deviation);

	cout << std::fixed;
	cout << setprecision(1);
	cout << deviation;
	



	return 0;
}
