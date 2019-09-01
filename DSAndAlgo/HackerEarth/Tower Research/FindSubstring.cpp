#include<iostream>
#include<vector>
#include<string>


using namespace std;

const int noOfChars = 256;

string smallestSubString(const string& str, const string& pat)
{
	string res="-1";
	int lenStr = str.length();
	int lenPat = pat.length();

	
	if (lenStr < lenPat)
	{		
		return res;
	}

	int hashPat[noOfChars] = { 0 };
	int hashStr[noOfChars] = { 0 };

	for (const char& ch : pat)
		hashPat[ch]++;

	int start = 0, end = 0, minLen=INT_MAX,count=0;
	bool found = false;
	for (int i = 0; i < lenStr; i++)
	{
		char ch = str[i];
		hashStr[ch]++;
		if (hashPat[ch] && hashStr[ch] <= hashPat[ch])
			count++;
		if (count == lenPat)
		{
			while (hashPat[str[start]]==0 || hashPat[str[start]] > hashStr[str[start]]  )
			{
				if (hashPat[str[start]] > hashStr[str[start]])
					hashPat[str[start]] --;
				start++;
			}

			int len = i - start + 1;
			if (minLen > len)
			{
				minLen = len;
				found = true;
			}

		}

	}

	if (found)
	{
		res = str.substr(start, minLen);
	}	

	return res;
	
}

int main()
{

	int T;
	cin >> T;
	while (T--)
	{
		cin.ignore();		
		string str1, str2;
		getline(cin,str1);
		getline(cin, str2);

		cout << smallestSubString(str1, str2) << endl;
	}

	return 0;
	
}