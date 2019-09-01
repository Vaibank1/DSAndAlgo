#include<map>//RB Tree
#include<unordered_map>//Haah Table

#include<iostream>
#include<conio.h>
#include<cmath>
#include<string>
#include<queue>
#include <functional>
using namespace std;


int main()
{
	//Key unique
	multimap<int, string> mp;
	unordered_map<int, string> ht;
	int a;
	string s;
	//pair<iterator pos,bool success>
	for (int i = 0; i < 10; i++)
	{
		a = rand() % 10;
		s = to_string(rand() % 10);
		mp.insert(make_pair(a, s));
		//mp[a] = s;
		cout << a << "\t" << s << endl;

		
	}

	cout << "\n\n\n";
	map<int, string>::iterator it;
	pair<map<int, string>::iterator, map<int, string>::iterator> result;

	/*if (mp.end() != (it=mp.find(1) ))
	{
		cout << it->first << "\t" << it->second;
	}*/
	result = mp.equal_range(1);
	for (it = result.first; it != result.second; ++it)
	{
		cout << it->first << "\t" << it->second<<endl;

	}


	priority_queue<int, vector<int>, std::greater<int>> heap;

	for (int i = 0; i < 100; i++)
	{
		heap.push(rand() % 100+1);
	}

	while(!heap.empty())
	{
		cout << heap.top() << "\t";
		heap.pop();
	}
 	return 0;

}