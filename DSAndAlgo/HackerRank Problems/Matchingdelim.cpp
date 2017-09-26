#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string str;
	while (true)
	{
		cin >> str;
		stack<char> stk;
		for (int i = 0; i<str.length(); i++)
		{
			if (stk.empty() || str[i] == '(' || str[i] == '{' || str[i] == '[')
			{
				stk.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (stk.top() != '(')
				{
					cout << "False";
					break;
				}
				else
					stk.pop();

			}
			else if (str[i] == '}')
			{
				if (stk.top() != '{')
				{
					cout << "False";
					break;
				}
				else
					stk.pop();

			}
			else if (str[i] == ']')
			{
				if (stk.top() != '[')
				{
					cout << "False";
					break;
				}
				else
					stk.pop();

			}



		}
		if (stk.empty())
			cout << "True";

		cout << endl;

	}
	return 0;
}
