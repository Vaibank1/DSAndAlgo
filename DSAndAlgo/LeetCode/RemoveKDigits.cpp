
#include<string>
#include<deque>

using namespace std;


//string removeKdigits(string num, int k) {
//
//	if (k == 0)
//		return num;
//
//	deque <char> dq;
//	int i;
//	for (i = 0; i <= k;i++ ) {
//		char ch = num[i];
//		if (dq.empty()) {
//			dq.push_back(ch);
//			continue;
//		}
//
//		while (!dq.empty() && dq.back() > ch)
//			{
//			dq.pop_back();
//		}
//		dq.push_back(ch);
//	}
//	string res;
//	
//	for ( i; i < num.length(); i++)
//	{
//		res += dq.front();
//		dq.pop_front();
//
//		char ch = num[i];
//		if (dq.empty()) {
//			dq.push_back(ch);
//			continue;
//		}
//
//		while (!dq.empty() && dq.back() > ch)
//		{
//			dq.pop_back();
//		}
//		dq.push_back(ch);
//
//	}
//	res += dq.front();
//	dq.pop_front();
//
//	string out;
//	bool isDigitNonZero = false;
//	for (int i = 0; i < res.length(); i++) {
//	
//		if (res[i] == '0' && !isDigitNonZero)
//			continue;
//		isDigitNonZero = true;
//		out.push_back(res[i]);
//	}
//
//	return out.length()==0?"0":out;
//}


string removeKdigits(string num, int k) {
	string ans;
	for (auto c : num) {
		while (!ans.empty() && k > 0 && ans.back() > c) {
			--k;
			ans.pop_back();
		}
		ans.push_back(c);
		if (ans.size() == 1 && ans.back() == '0')
			ans.pop_back();
	}
	while (k-- && !ans.empty())
		ans.pop_back();
	return ans.empty() ? "0" : ans;
}

// Driver program to test above function 
int main()
{
	string str = "1432219";
	int n = 3;
	string out = removeKdigits(str, n);
	return 0;
}

