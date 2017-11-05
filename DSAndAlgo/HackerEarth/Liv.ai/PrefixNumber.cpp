#include<iostream>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int count = 0;
	
	for (int i = 1; i < str.length()/2+1; i++)
	{
		string a = str.substr(0, i);
		string b = str.substr(i);
		if (b[0] == '0' || a[0]=='0')
			continue;
		size_t found = b.find(a);
		if (found == 0)
			count++;
		//string  tmpB = b;
		//while(tmpB.size()!=0)
		//{
		//	if (a == tmpB)
		//	{
		//		//no trialing zeroes
		//		if (b[0] != '0' && a[0]!='0')
		//		{					
		//			count++;
		//			break;
		//		}
		//	}
		//	tmpB.pop_back();
		//}
		
	
	}

	cout << count;
	

	return 0;

}