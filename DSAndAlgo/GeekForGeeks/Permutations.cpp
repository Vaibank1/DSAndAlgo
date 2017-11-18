#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<string>

using namespace std;

int cnt = 0;

void permuatation(const vector<char>& arr, vector<char>& output, int ln , vector<int>& visited)
{
	if (ln == arr.size())
	{
		copy(output.begin(),output.end(),ostream_iterator<char>(cout));
		cout << endl;
		cnt++;
		return;
	}

	for (int i=0;i<visited.size();i++)
	{
		if (visited[ i] != 1)
		{
			visited[ i] = 1;
			output.push_back( arr[i]);
			permuatation(arr, output, ln + 1, visited);
			output.pop_back();
			visited[i] = 0;
		}
	}

}


void permuteUntil(const string& input, string& output, vector<int>& countArr, int n )
{
	if (output.length() == n)
	{
		cout << output<< endl;
		cnt++;
		return;
	}

	for (int i = 0; i < countArr.size(); i++)
	{
		if (countArr[i])
		{
			countArr[i]--;
			output.push_back(input[i]);
			permuteUntil(input, output, countArr, n);
			countArr[i]++;
			output.pop_back();
		}
	}
}


void permute(const vector<char>& arr)
{
	


	map<char, int> mp;
	for (char ch : arr)
	{
		mp[ch]++;
	}
	int index = 0;
	vector<int> countAr(mp.size());
	string input,output;
	

	for (auto it : mp)
	{
		countAr[index] = it.second;
		input.push_back( it.first);
		index++;
	}

	permuteUntil(input, output, countAr, arr.size());

}



int main()
{
	vector<char> arr = {'A','A','B','C'}, output;
	vector<int> visited(arr.size(),0);

	/*permuatation(arr, output, 0, visited);
	*/

	permute(arr);
	cout << cnt << endl;


	return 0;
}