#include "stdafx.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
using namespace std;



int process(const string& str)
{
	bool charList[26]={false};
	

	int curCount[26]={0};
	
	
	
	int count=0;
    for(int i=0; i < str.length();++i)
    {
		
		if(!charList[tolower(str[i]) -'a'] ) 
		{	
			charList[tolower(str[i]) -'a'] = true;	      
			count++;
		}
	
        
    }
	int start=0, curChar=0,minSize=INT_MAX;
	for(int i=0; i<str.length();++i)
	{
		if(curCount[tolower(str[i]) -'a'] ==0) 
		{
			curChar++;
			
		}
		curCount[tolower(str[i]) -'a'] ++;
		if(curChar == count)
		{
			//reduce the window
			while(curCount[tolower(str[start]) -'a'] >1)
			{
				if(curCount[tolower(str[start]) -'a'] >1)
					curCount[tolower(str[start]) -'a'] --;				
				start++;

			}
			int cur_size= i-start+1;
			minSize=min(cur_size,minSize);

		}
	
	}

	return minSize;
	
    
}
int main() {
	//code
	int T;
	cin>>T;
	for(int i =0; i <T ; ++i)
	{
	    string str;
	    cin>>str;
	    cout<<process(str)<<endl;
	}
	
	return 0;
}