#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
#include<iostream>
#include<string>

using namespace std;



int minLength(string text, vector < string > keys) {

	int answer =INT_MAX;
	text += " $";
	int start = 0;
	string del = " ";
	int end = 0;
	vector<string> words;
	bool isValid = false;
	while ((end = text.find(del, start)) != std::string::npos)
	{
		string sbstr = text.substr(start, end - start);
		for (int i = 0; i < sbstr.length(); i++)
		{
			if (sbstr[i] != ' ')
			{
				isValid = true; break;
			}
		}
		if (isValid)
		{
			words.push_back(text.substr(start, end - start));
			isValid = false;
		}
		start = end + 1;
	}

	start = 0; end = 0;
	unordered_map<string, int> mp;
	int totalKeys = 0,uniqueKeys=0;
	int minSize = INT_MAX;
	int minStart = 0;
	bool allKeysPresent = false;
		for (int i = 0; i < words.size(); i++)
	{
			for (int k = 0; k < keys.size(); k++) {
				if (keys[k] == words[i]) {
					totalKeys++;
					if (mp[words[i]] == 0)
						uniqueKeys++;
					mp[words[i]]++;

				}
			}
		if (totalKeys >= keys.size())
		{
			while (start <i)
			{
				unordered_map<string, int>::iterator it = mp.find(words[start]);
				if (mp.end() == it)
					start++;
				else
				{
					if (it->second > 1)
					{
						it->second--;
						totalKeys--;
						start++;
					}
					else
					{
						break;
					}

				}
			}

			if (uniqueKeys == keys.size())
			{
				allKeysPresent = true;
				int cur_size = i - start + 1;
				if (cur_size < minSize)
				{
					minStart = start;
					minSize = cur_size;
					end = i;
				}
			}
		}
	
		

	}

	if (!allKeysPresent)
		answer = -1;
	else
	{
		answer = 0;
		for (int i = minStart; i < minStart+minSize; i++)
		{
			answer += words[i].length();
		}
		answer += minSize-1;
	}
	return answer;
}
#define MAXVAL (int)1e9

int minimumLength(string text, vector < string > keys) {
	int answer = MAXVAL;
	text += " ";
	map<string, int> m;
	set<int> s;
	string word = "";
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ') {
			for (int j = 0; j < keys.size(); j++) {
				if (word == keys[j]) {
					if (!s.empty() && m.find(word) != m.end())
						s.erase(m[word]);
					s.insert(i - word.size());
					m[word] = i - word.size();
					if (s.size() == keys.size()) {
						set<int>::iterator it = s.begin();
						int a = i - (*it);
						if (a < answer)
							answer = a;
					}
					break;
				}
			}
			word = "";
		}
		else
			word += text[i];
	}
	if (answer == MAXVAL)
		answer = -1;
	return answer;
}


int main() {

	string text, buf;
	vector < string > keys;

	getline(cin, text,'\n');
	int keyWords;
	cin >> keyWords;
	for (int i = 0; i < keyWords; i++) {
		cin >> buf;
		keys.push_back(buf);
	}
	cout << minLength(text, keys) << endl;

	cout << minimumLength(text, keys) << endl;


	return 0;
}