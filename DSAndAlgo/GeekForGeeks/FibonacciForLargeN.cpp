#include<iostream>
#include<vector>


using namespace std;

typedef  unsigned long long ULL;

void mulitply(ULL F[2][2], ULL M[2][2])
{
	ULL x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	ULL y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	ULL z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	ULL w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}


void power(ULL F[2][2], ULL n)
{
	if (n < 2)
		return ;

	ULL matrix[2][2] = { { 1,1, },{ 1,0 } };

	for (ULL i = 0; i < n - 1; i++)
	{

		mulitply(F, matrix);
	}

}

void optimizedPower(ULL F[2][2], ULL n)
{
	if (n < 2)
		return;

	ULL matrix[2][2] = { { 1,1, },{ 1,0 } };

	power(F, n/2);
	mulitply(F, F);

	if (n % 2)
	{
		mulitply(F, matrix);
	}
	

}


ULL fibMatrix(ULL n)
{
	ULL result = 0;

	ULL resMatrix[2][2] = { { 1,1, },{ 1,0 } };

	
	power(resMatrix, n - 1);
	//optimizedPower(resMatrix, n - 1);
	 
	return resMatrix[0][0];

}



int main()
{

	ULL N =45;
	cout << fibMatrix(N);
	return 0;
}