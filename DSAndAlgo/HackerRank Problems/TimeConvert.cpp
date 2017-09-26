#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string  str;
	cin >> str;
	if (str[str.length() - 2] == 'A')
	{
		cout << str.substr(0, str.length() - 2);
	}
	else
	{
		str.erase(str.length() - 2, 2);
		int num = stoi(str.substr(0, 2));
		num += 12;
		str[1] = num % 10 + '0';
		num /= 10;
		str[0] = num % 10 +'0';
		cout << str;
	}
	return 0;
}
