#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

priority_queue<int> maxHeapLeft;
priority_queue<int, vector<int>, greater<int>> minHeapRight;

void calMedian(double  x, double& median)
{
	if (minHeapRight.size() > maxHeapLeft.size())
	{
		if (x > minHeapRight.top())
		{
			maxHeapLeft.push(minHeapRight.top());
			minHeapRight.pop();
			minHeapRight.push(x);
		}
		else
		{
			maxHeapLeft.push(x);
		}
			median = (maxHeapLeft.top() + (double)minHeapRight.top()) / (double)2;

		
	}
	else if( minHeapRight.size() == maxHeapLeft.size())
	{
		if (x > median)
		{
			minHeapRight.push(x);
			median = minHeapRight.top();

		}
		else
		{
			maxHeapLeft.push(x);
			median = maxHeapLeft.top();
		}
		
	}
	else
	{
		if (x < maxHeapLeft.top())
		{
			minHeapRight.push(maxHeapLeft.top());
			maxHeapLeft.pop();
			maxHeapLeft.push(x);
		
		}
		else
		{
			minHeapRight.push(x);
		}
		median = (maxHeapLeft.top() + (double)minHeapRight.top()) /(double) 2;

	}

}


int main()
{
	// stream of integers
	double arr[] = { 5, 15, 10, 20, 3 };
	double median = 0;//stores the median 

					  // size of stream
	int n = 5;

	// reading elements of stream one by one
	for (int i = 0; i < n; i++)
	{
		// calculating new median for each 
		// new element added to the stream
		calMedian(arr[i], median);
		cout <<  median << "\n";
	}
	return 0;
}