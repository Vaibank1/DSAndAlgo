#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>
#include<unordered_map>
#include<array>

using namespace std;




int main()
{
	{
		string str = "a b c d b a";
		int start = 0,end=0;
		string delim = " ";

		unordered_map<string, vector<int>> map;

		while (string::npos !=( end=str.find(delim, start)))
		{
			string substr = str.substr(start, end - start) ;
			if (map.end() == map.find(substr))
			{
				vector<int> vec;
				vec.push_back(start);
				map.insert({ substr, vec });
			
			}
			else
			{
				map[substr].push_back(start);
			}

			start = end+ 1;
		}
		string substr = str.substr(start);
		if (map.end() == map.find(substr))
		{
			vector<int> vec;
			vec.push_back(start);
			map.insert({ substr, vec });

		}
		else
		{
			map[substr].push_back(start);
		}


	

	}

	return 0;
}