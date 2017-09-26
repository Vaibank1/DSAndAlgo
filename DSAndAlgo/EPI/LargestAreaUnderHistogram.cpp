#include"Node.h"



int maxAreaUnderHistogram(const vector<int> & arr)
{
	stack<int> stk;
	pair<int, int> indexes;
	int area = 0, maxArea = 0, top = 0;
	int i = 0;
	for (i = 0; i < arr.size();)
	{
		
		if (stk.empty() || arr[stk.top()] <= arr[i])
			stk.push(i++);
		else
		{
			top = stk.top();
			stk.pop();
			if (stk.empty())
			{
				area = arr[top] * i;

			}
			else
			{
				area = arr[top] * (i - stk.top() - 1);

			}
			if (maxArea < area)
			{
				maxArea = area;
				indexes.first = top;
				indexes.second = i;
			}


		}
	}
	while (!stk.empty())
	{
		top = stk.top();
		stk.pop();
		if (stk.empty())
		{
			area = arr[top] * i;


		}
		else
		{
			area = arr[top] * (i - stk.top() - 1);

		}
		if (maxArea < area)
		{
			maxArea = area;
			indexes.first = top;
			indexes.second = i;
		}
	}

	return maxArea;
}

int main()
{

	vector<int> arr = {1,2,3,4,5,6};
	

	cout << "Max Area " << maxAreaUnderHistogram(arr);

	_getch();
	return 0;

}