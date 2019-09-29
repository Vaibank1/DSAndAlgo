#include<vector>
#include<algorithm>

using namespace std;


int solution(vector<int> &A, vector<int> &B) 
{

	if (A.size() == 0)
		return 0;
	if (A.size() == 1)
		return 1;

	vector<pair<int,int>> intervals;
	for (int i = 0; i < A.size(); i++)
		intervals.push_back(make_pair( A[i],B[i] ));
	sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
		return a.first < b.first; });

	pair<int, int> res = intervals[0];
	int count = 1;
	for (auto & it : intervals) {
		if (res.second >= it.first) {
			if (res.second < it.second)
				res.second = it.second;
		}
		else
		{
			res = it;
			count++;
		}
	}

	return count;

}




vector<vector<int>> merge(vector<vector<int>>& intervals) {
	
	if (intervals.size() == 0)
		return vector<vector<int>>();
	if (intervals.size() == 1)
		return intervals;


	sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
		return a[0] < b[0]; });

	vector<vector<int>> res;
	res.push_back(intervals[0]);
	for (auto & it : intervals) {
		if (res.back().at(1) >= it.at(0)) {
			if (res.back().at(1) < it.at(1))
				res.back().at(1) = it.at(1);
		}
		else
			res.push_back(vector<int>{it[0],it[1]});
	}

	return res;

}


int main()
{
	//vector<vector<int>> in = { {1,3 }, { 2,6 }, { 8,10 }, { 15,18 } };

	//merge(in);

	vector<int> A = {1,12,42,70,36,-4,43,15};
	vector<int> B = {5,15,44,72,36,2,69,24};
	solution(A, B);
	return 0;
}