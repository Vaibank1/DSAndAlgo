
#include<iostream>

int main()
{

	int num = 1;
	char* ch = (char*)&num;

	std::cout << *ch;

	int ones = 0, twos = 0;
	int A[] = { 1,1,1,1,2,3,4 };
	int next_ones, next_twos;
	for (const int &i: A) {
		next_ones= (-1 & ones) |(i & -ones & -twos);
		next_twos = (-i & twos) | (i & ones);
		ones = next_ones, twos = next_twos;
	}
	return 0;
}