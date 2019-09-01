#include<iostream>
#include<stack>


class MaxStack
{
	int minNum;
	std::stack<int> maxStk;
public:
	void push(int num)
	{
		int numToBeInserted = num;
		if (maxStk.empty())
			minNum = num;
		else if (num < minNum){
			numToBeInserted = 2 * num - minNum;
			minNum = num;
		}

		maxStk.push(numToBeInserted);
	
	}


	int  pop()
	{
		if (maxStk.empty())
			return -1;
		int poppedNum = maxStk.top();
		int actualNum = poppedNum;
		maxStk.pop();
		if (poppedNum < minNum) {
			minNum = 2 * minNum - poppedNum;
			actualNum = (poppedNum + minNum) / 2;
		}

		return actualNum;

	}
	int getMin()
	{
		return minNum;
	}

};




int main()
{

	MaxStack stk;
	int length = 5;
	for (size_t i = 0; i < length; i++)
	{
		int num = std::rand()%10;
		stk.push(num);
		std::cout << "Number inserted is : " << num<<std::endl;

	}


	for (size_t i = 0; i < length; i++)
	{
		std::cout << "Min is : " << stk.getMin()<< std::endl;
		int num = stk.pop();
		std::cout << "Popped num is  : " << num << std::endl;

	}


	return 0;




}