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


bool checkAns(const vector <int>& a)
{
	bool isInc = true, isDec = true;

	//check increasing order
	for (int i = 0; i < a.size()-1; ++i)
	{
		if (a[i] > a[i + 1])
			isInc =  false;


	}
	//if got here
	for (int i = 0; i < a.size() - 1; ++i)
	{
		if (a[i] < a[i + 1])
			isDec = false;


	}
	if (isInc || isDec)
		return true;
	else
		return false;

}

int recurse(const vector <int>& coders, vector <int>& ans, int num) {
	if (ans.size() == 3)
	{
		if (checkAns(ans))
			return 1;
		else
			return 0;
	}
	if (ans.size() > 3)
		return 0;
	if (num >= coders.size())
		return 0;
	int count1 = 0, count2 = 0;
	int pre = 0;
	if(!ans.empty())
		pre = ans[ans.size() - 1];
	int cur = coders[num];
	if (ans.empty() || ( pre > cur || pre<cur))
	//include this num
	{
		ans.push_back(coders[num]);
		count1 = recurse(coders, ans, num + 1);
		ans.pop_back();
	}
	//exclude this elem
	count2 = recurse(coders, ans, num + 1);

	return count1 + count2;


}

int getCountOfPossibleTeams(vector <int> coders) {

	vector <int> ans;
	return recurse( coders, ans,  0);
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	int res;
	int coders_size = 0;
	cin >> coders_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<int> coders;
	for (int i = 0; i < coders_size; i++) {
		int coders_item;
		cin >> coders_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		coders.push_back(coders_item);
	}

	res = getCountOfPossibleTeams(coders);
	cout << res << endl;

	
	return 0;
}