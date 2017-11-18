#include<iostream>
#include<string>
using namespace std;

void swap(char* ch1, char* ch2)
{

	char ch = *ch1;
	*ch1 = *ch2;
	*ch2 = ch;	

}


void recurse(string &str, int index)
{
	if (index >= str.length() || index + 1 >= str.length())
	{
		cout << str << endl;
		return;
	}

	//no swaps
	recurse(str, index + 1);

	
	//swap
	swap(&str[index], &str[index + 1]);
	recurse(str, index + 2);
	swap(&str[index], &str[index + 1]);

}



int main()
{

	string str = "12345";

	recurse(str, 0);
	return 0;
}