#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define ULL unsigned long long 

vector<int> maxVal(11);

/* This function calculates (ab)%c */
int modulo(int a, int b, int c) {
	ULL x = 1, y = a; // long long is taken to avoid overflow of intermediate results
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x*y) % c;
		}
		y = (y*y) % c; // squaring the base
		b /= 2;
	}
	return x%c;
}

bool Fermat(ULL p, int iterations) {
	if (p == 1) { // 1 isn't prime
		return false;
	}
	for (int i = 0; i<iterations; i++) {
		// choose a random integer between 1 and p-1 ( inclusive )
		long long a = rand() % (p - 1) + 1;
		// modulo is the function we developed above for modular exponentiation.
		if (modulo(a, p - 1, p) != 1) {
			return false; /* p is definitely composite */
		}
	}
	return true; /* p is probably prime */
}
/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long mulmod(long long a, long long b, long long c) {
	long long x = 0, y = a%c;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x + y) % c;
		}
		y = (y * 2) % c;
		b /= 2;
	}
	return x%c;
}
/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long p, int iteration) {
	if (p<2) {
		return false;
	}
	if (p != 2 && p % 2 == 0) {
		return false;
	}
	long long s = p - 1;
	while (s % 2 == 0) {
		s /= 2;
	}
	for (int i = 0; i<iteration; i++) {
		long long a = rand() % (p - 1) + 1, temp = s;
		long long mod = modulo(a, temp, p);
		while (temp != p - 1 && mod != 1 && mod != p - 1) {
			mod = mulmod(mod, mod, p);
			temp *= 2;
		}
		if (mod != p - 1 && temp % 2 == 0) {
			return false;
		}
	}
	return true;
}

ULL maxDiv(ULL n)
{
	if (n <= 0)
		return 0;
	//check if it is not prime
	if (n < maxVal.size() - 1)
		return maxVal[n];

	bool isPrime = true;
	int p = 1;
	if (n % 2 == 0)
		p = 2;
	else {
		if (Fermat(n, 20))
		{
			isPrime = Miller(n, 20);
			if(isPrime)
				return n + 1;
		}
		

	for (int i = 3; i <= sqrt(n)+1; i+=2)
		if (n%i == 0)
		{
			p = i;
			break;
		}
	}
	if (p == 1)
		return n + 1;

	return maxDiv(n / p) + n;

}


long long checkEachDivisor(long long n)
{
	if (n <= 0)
		return 0;
	//check if it is not prime
	if (n < maxVal.size() - 1)
		return maxVal[n];

	for (int i = 2; i <= sqrt(n)+1; i ++)
	{
		if (i != 2 && i % 2 == 0)
			continue;
		if (n%i == 0)
		{
			cout << "Divisor " << i << " ans =";
			cout<<checkEachDivisor(n / i);

		}
		cout << endl;
	}





}
int n = 100000;
vector<ULL> val(n, 0);
void fillBottomUp()
{
	//int n = 1000;
	///*ULL *  val = new ULL[n];*/
	//vector<ULL> val(n, 0);
	val[1] = 1;
	val[2] = 3;
	val[3] = 4;
	val[4] = 7;
	val[5] = 6;
	
	for (int i = 6; i < n; i++)
	{
		for (int j = 2; j <= i / 2; j++)
		{
			if (i%j == 0)
			{
				val[i] = max(val[i], val[j] * (i / j) + 1);

			}
		}
		if (val[i] == 0)
			val[i] = i + 1;

	}

	int i = 0;
}

int main()
{
	maxVal[1] = 1;
	maxVal[2] = 3;
	maxVal[3] = 4;
	maxVal[4] = 7;
	maxVal[5] = 6;
	maxVal[6] = 10;
	maxVal[7] = 8;
	maxVal[8] = 15;
	maxVal[9] = 13;
	maxVal[10] = 16;

/*
	int n;
	cin >> n;

	
	ULL ans = 0, tmp = 0;;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		ans += maxDiv(tmp);
	}


	cout <<ans;
*/
	fillBottomUp();
	for (int i = 6; i < n; i++) {
		long long va = maxDiv(i);
		if (va != val[i])
		{
			cout << "Error for " << i << endl;
			cout << "the number from formula : " << va<<endl;
			cout << "the number from bottomup : " << val[i]<<endl;
		}
	}
	


	return 0;

}