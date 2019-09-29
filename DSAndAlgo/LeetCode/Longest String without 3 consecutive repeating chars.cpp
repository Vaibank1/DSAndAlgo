#include<string>
#include<iostream>
#include<list>
using namespace std;





void addChar(string & res, const char& ch, int& count)
{
	count--;
	res.push_back(ch);
	if (count != 0)
	{
		count--;
		res.push_back(ch);
	}

}

string solution(int A, int B) {
	// write your code in C++14 (g++ 6.2.0)
	string res;
	if (A < 0 || B < 0)
		return "";
	if (A == 0 && B == 0)
		return "";
	if (A == 0)
	{
		addChar(res, 'b', B);
		return res;
	}
	else if (B == 0) {
		addChar(res, 'a', A);
		return res;
	}


	int largerNumTurn = 1;
	char largerChar = A >= B ? 'a': 'b';
	char otherChar = largerChar == 'a' ? 'b' : 'a';
	if (A < B) {
		int C = A;
		A = B;
		B = C;
	}
	while (A != 0 && B != 0) {
		if (largerNumTurn) {
			addChar(res, largerChar, A);
		}
		else
		{
			B--;
			res.push_back(otherChar);
			if (B!=0 && B >= A)
			{
				B--;
				res.push_back(otherChar);
			}

		}

		largerNumTurn ^= 1;
	
	}
	
	char lastChar = res.back();
	size_t len = res.length();
	if (A != 0) {
		if (lastChar == otherChar) {
			addChar(res, largerChar, A);
		}
		else {
			if (len - 2 > 0 && res[len - 2] != largerChar) {
				addChar(res, largerChar, A);
			}
		}

	}
	else if (B != 0) {
		if (lastChar == largerChar) {
			addChar(res, otherChar, B);
		}
		else {
			if (len - 2 > 0 && res[len - 2] != otherChar) {
				addChar(res, otherChar, B);
			}
		}
	}
	
	return res;


}





int main()
{
	

	cout << solution(1,2);

}