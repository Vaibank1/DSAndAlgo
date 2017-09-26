#include "stdafx.h"
#include <conio.h>
#include <vector>
#include <iostream>

#include <math.h>
#include <string>


using namespace std;

string richieRich(string s, int n, int k){
    // Complete this function
    bool odd = n%2==1?true:false;
    int numOfChangesRequired=0;
    //check for the number of changes required
    for(int i=0;i<n/2;++i)
    {
        if(s[i] != s[n-i-1])
            numOfChangesRequired++;
        
    }
    char* result = new char[n+1];
	result[n]='\0';
	
    if(k< numOfChangesRequired)
        return "-1";
	int left=0,right=n-1;
	
	bool* mark = new bool[n];
	while(left <= right)
	{
		if(left == right)
		{
			result[left]=s[left];
			break;
		}
		else if(s[left] != s[right])
		{
			if(s[left] < s[right])
			{
					result[left]=result[right]=s[right];
					mark[left]= true;
			}
			else 
			{
				result[left]=result[right]=s[left];
					mark[right]= true;
				
			}
			
			k--;
		}
		else
		{
			result[left]=result[right]=s[left];
		}

		left++;right--;
	}

	if(k >0)
	{
		left=0,right=n-1;
		while (left <= right)
		{
			
				if(left==right && result[left] != '9' && k>0)
				{
					result[left]='9';
					k--;
					break;
				}

				if (result[left] != '9' && mark[left]== false && mark[right] == false && k-2>=0)
				{
					k-=2;
					result[left]=result[right]='9';
					mark[left]=mark[right]=true;
				}
				else if(result[left] != '9' && (mark[left]== true || mark[right] == true) && k>0)
				{
					k-=1;
					result[left]=result[right]='9';
					mark[left]=mark[right]=true;
				}
			

			left++;right--;
		}
	
	}
	

	s= result;
	delete[] result;
    return s;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string result = richieRich(s, n, k);
    cout << result << endl;
    return 0;
}