#include "stdafx.h"
using namespace std;

string feeOrUpfront(int n, int k, int x, int d, vector <int> p) {
    // Complete this function
    //calculate the transaction charges
    double sumTrans=0;
	double dd = d;
    
    for(int i =0; i <n; i++)
    {
        sumTrans += max( (double)k ,(double)(((double)p[i]*(double)x)/100));          
        
    }
    if((sumTrans - dd) < std::numeric_limits<double>::epsilon())
		return "fee";

    return max(sumTrans,dd) == sumTrans ?"upfront": "fee";
    
    
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int k;
        int x;
        int d;
        cin >> n >> k >> x >> d;
        vector<int> p(n);
        for(int p_i = 0; p_i < n; p_i++){
           cin >> p[p_i];
        }
        string result = feeOrUpfront(n, k, x, d, p);
        cout << result << endl;
    }
    return 0;
}
