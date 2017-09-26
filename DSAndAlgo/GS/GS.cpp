#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>
#include<stack>

using namespace std;

vector <string> getShrunkArray(vector <string> inputArray, int burstLength) {

	stack<string> stk;
	string cur, pre;
	stack<string> bk;
	int repeat = 1;
	for (int i = 0; i < inputArray.size(); ++i)
	{
		cur = inputArray[i];
		if (stk.empty())
		{
			stk.push(cur);
			continue;
		}

		else if ( cur != stk.top())
		{
			pre = stk.top();
			stk.pop();
			while (!stk.empty() && stk.top() == pre)
			{
				stk.pop();
				repeat++;
			}
			
			if (repeat < burstLength)
			{
				while (repeat)
				{
					stk.push(pre);
					repeat--;

				}
				
			}
			

		}
		stk.push(cur);
		

		repeat = 1;

	}

	pre = stk.top();
	stk.pop();
	while (!stk.empty() && stk.top() == pre)
	{
		stk.pop();
		repeat++;
	}

	if (repeat < burstLength)
	{
		while (repeat)
		{
			stk.push(pre);
			repeat--;

		}

	}



	vector <string> res;
	while (!stk.empty())
	{
		res.push_back((stk.top()));
		stk.pop();
	}
	reverse(res.begin(), res.end());
	return res;

}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	vector <string> res;
	int inputArray_size = 0;
	cin >> inputArray_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<string> inputArray;
	for (int i = 0; i < inputArray_size; i++) {
		string inputArray_item;
		getline(cin, inputArray_item);
		inputArray.push_back(inputArray_item);
	}

	int burstLength;
	cin >> burstLength;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = getShrunkArray(inputArray, burstLength);
	cout << "ANS" << endl << endl;
	for (int res_i = 0; res_i < res.size(); res_i++) {
		cout<< res[res_i] ;
	}

	//fout.close();
	return 0;
}