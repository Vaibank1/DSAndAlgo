#include"Node.h"


void sort(stack<int> & stk)
{
	stack<int> buffer;
	//empty the stack
	while (!stk.empty())
	{
		buffer.push(stk.top());
		stk.pop();
	}
	//now in insert in sorted order
	while (!buffer.empty())
	{
		int tmp = buffer.top();
		buffer.pop();
		if (stk.empty() || stk.top() <= tmp)
			stk.push(tmp);
		else
		{
			//current item is smaller than top of stk.
			while ( !stk.empty() && tmp < stk.top())
			{
				buffer.push(stk.top());
				stk.pop();
			}
			stk.push(tmp);
		}
	}

}


void insert( stack<int> & stk, int tmp)
{
	if (stk.empty() || tmp >= stk.top())
		stk.push(tmp);
	else
	{
		int num = stk.top();
		stk.top();
		insert(stk, tmp);
		stk.push(num);
	}
}

void recursiveSort(stack<int>& stk)
{
	if (!stk.empty())
	{
		int tmp = stk.top();
		stk.pop();
		recursiveSort(stk);
		insert(stk, tmp);
	}
}

int main()
{
	stack<int> stk;
	int N = 10;
	for (size_t i = 0; i < N; i++)
	{
		stk.push((rand() % 13 + rand() % 23) % 20);
	}
	
	//sort(stk);
	recursiveSort(stk);

}