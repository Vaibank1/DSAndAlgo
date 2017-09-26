#include "stdafx.h"
#include <algorithm>

using namespace std;

struct stock
{
unsigned long long  dayNum;
unsigned long long  price;
stock(int a , int b):dayNum(a),price(b)
{}
stock()
{
dayNum=0;
price=0;
}
};

bool sortVec(stock& x, stock& y)
{
	if(x.price < y.price)
		return true;
	return false;
}

long buyMaximumProducts(int n, unsigned long long  k, vector<stock>& a) {
    // Complete this function
	unsigned long long  num =0;
	unsigned long long  temp=0;
	unsigned long long  stocksBought=0;
	std::sort(a.begin(),a.end(),sortVec);
	for (int i = 0; i < n; i++)
	{
		if(num >= k)
		{
			//cash reserve is over
			break;
		}

		//try to buy all stocks for given day
		temp = a[i].dayNum*a[i].price;

		if(num + temp <=k)
		{
			//add all stocks 
			num+=temp;
			stocksBought +=a[i].dayNum;
		}
		else
		{
			//cash limit reached
			//buy as much we can

			int cashRemain = k-num;

			//how much stocks we can buy
			int numOfStocksBought = cashRemain/a[i].price;
			stocksBought+=numOfStocksBought;
			num += numOfStocksBought*a[i].price;
		
		}
	}

	return stocksBought;
}


int main() {
    int n;
    cin >> n;
    vector<stock> arr;
	int value=0;
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> value;
	   arr.push_back(stock(arr_i+1,value));
    }
    unsigned long long k;
    cin >> k;
    long result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}
