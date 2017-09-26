
#include "stdafx.h"
#include <algorithm>

using namespace std;
//
//struct stock
//{
//	int time;
//	int price;
//
//	stock(int a , int b) : time(a),price(b){}
//
//};

int binarySearch(vector<int>& vec, int val)
{
	  vector<int>::iterator first = std::lower_bound(vec.begin(),vec.end(),val);
		if(first == vec.end())
			return -1;
		return first - vec.begin(); 
}

int main() {
    int n;
    int q;
    cin >> n >> q;
    vector<int> t(n);
    for(int t_i = 0; t_i < n; t_i++){
       cin >> t[t_i];
    }
    vector<int> p(n);
    for(int p_i = 0; p_i < n; p_i++){
       cin >> p[p_i];
    }

	
	vector<int> maxPriceAtTime;
	int maxPrice=0;
	for (int i = 0; i < n; i++)
	{
		maxPrice = max(maxPrice,p[i]);
		maxPriceAtTime.push_back(maxPrice);

	}

	vector<int> maxPriceAfterTime(n);
	maxPrice =0;
	for (int i = n-1; i >= 0; i--)
	{
		maxPrice = max(maxPrice,p[i]);
		maxPriceAfterTime[i]=maxPrice;

	}
	int tmp=0;

	vector<int> ans;
    for(int a0 = 0; a0 < q; a0++){
        int _type;
        int v;
        cin >> _type >> v;

		if(_type == 1)
			// search query for time , where stock price is atleast become val
		{
			tmp =binarySearch(maxPriceAtTime,v);
			ans.push_back(tmp==-1?-1:t[tmp]);
			/*if(-1 == tmp )
				cout<<"-1";
			
			else 
				cout<<t[tmp];*/

		}

		else 
		{
			//query to get max value after time v
			tmp = binarySearch(t,v);
			//cout<<maxPriceAfterTime[tmp];
			ans.push_back(tmp==-1?-1:maxPriceAfterTime[tmp]);
		}

		//cout<<endl;
    }


	for(int i=0;i<q;++i)
	{
		cout<<ans[i]<<endl;
	}
    return 0;
}