

#include <iostream>
#include <vector>

#include <conio.h>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	string sentence= "It is a pleasant day today";
	
	/*for(int i =0;i<s.length(),++i)
	{
		if(s[i] == ' ')
		{
			
		}
	}*/
	string delim=" ";
	int start=0;
	int end=sentence.find(delim);
	string max;
	int maxLn=0;
	while(end != std::string::npos)
	{
		string substr = sentence.substr(start,end-start);

		if(substr.length() !=0 && substr.length() %2 == 0 && maxLn<substr.length())
		{
			max = substr;
			maxLn = substr.length();
		}

		

		start = end + delim.length();
		end=sentence.find(delim, start);
	}
		string substr = sentence.substr(start,end);

		if(substr.length() !=0 && substr.length() %2 == 0 && maxLn<substr.length())
		{
			max = substr;
			maxLn = substr.length();
		}
	std::cout<<max;

	return 0;

}
