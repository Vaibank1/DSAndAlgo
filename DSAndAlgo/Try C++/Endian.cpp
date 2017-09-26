
#include<iostream>

int main()
{

	int num = 1;
	char* ch= (char*)&num;

	std::cout << *ch;
	return 0;
}