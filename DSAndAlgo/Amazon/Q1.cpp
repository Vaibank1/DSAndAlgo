#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> tokennize(const string & str) {

	size_t pos = str.find(" ");
	size_t initialPos = 0;

	vector<string> res;
	// Decompose statement
	while (pos != std::string::npos) {
		string substr = str.substr(initialPos, pos - initialPos);
		initialPos = pos + 1;
		pos = str.find(" ", initialPos);
		res.push_back(substr);
	}

	string substr = str.substr(initialPos, std::min(pos, str.size()) - initialPos + 1);
	res.push_back(substr);
	return res;
}

bool isold(string & str)
{
	for (auto & ch : str)
	{
		if (!isalpha(ch))
			return false;
		
	}

	return true;
}

bool compareBox(const string & str1, const string& str2)
{
	vector<string> token1, token2;
	token1 = tokennize(str1);
	token2 = tokennize(str2);

	bool isOld1 = isold(token1[1]);
	bool isOld2 = isold(token2[1]);
	if (isOld1 && !isOld2) {
		return true;
	}
	if (!isOld1 && isOld2)
		return false;
	
		int res = strcmp(token1[1].c_str(), token2[1].c_str());
		if (res < 0)
			return true;
		else if (res > 0)
			return false;


	int size = min(token1.size(), token2.size());

	for (int i = 2; i < size; i++)
	{
		int res = strcmp(token1[i].c_str(), token2[i].c_str());
		if (res == 0)
			continue;
		else
			return res < 0?true : false;
	}


	//compare the identifier
	return strcmp(token1[0].c_str(), token2[0].c_str());
	
}

vector<string> orderedJunctionBoxes(int numberOfBoxes, vector<string> boxList)
{
	// WRITE YOUR CODE HERE

	sort(boxList.begin(), boxList.end(), compareBox);
	return boxList;

	
}


int main()
{
	vector<string> boxList = {"x4 45 21 7", "wz3 55 54 398" };
	orderedJunctionBoxes(2,boxList);
	return 0;
	//	23280666002885
}
