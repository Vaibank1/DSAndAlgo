#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string  leftrotate(string str, int d)
{
	string s = str;
	reverse(s.begin(), s.begin() + d);
	reverse(s.begin() + d, s.end());
	reverse(s.begin(), s.end());
	return s;
}


string  rightrotate(string str, int d)
{
	string s = str;
	
	return leftrotate(s, s.length() - d);;
}

/*
* Complete the function below.
*/
string getShiftedString(string s, int leftShifts, int rightShifts) {
	// Write your code here.

	if (s.length() == 1)
		return s;
	int shift = leftShifts - rightShifts;
	if (shift == 0)
	{
		return s;
	}
	else if (shift>0)
	{
		return leftrotate(s, shift);
	}
	else
	{
		return rightrotate(s, -1 * shift);
	}




}
int main()
{
	cout << getShiftedString("abcd",1,2);

	return 0;
}
