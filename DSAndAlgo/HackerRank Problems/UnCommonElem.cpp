#include "stdafx.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

string uncommonBetweenCommon(vector < int > input1,vector < int > input2)
{
	
  std::stringstream ss;
	//Write code here
	std::sort(input1.begin(),input1.end());
	int len = input2.size();
	int* arr1 = new int[input1.size()];
	int* arr2 = new int[input2.size()];
	for(int i=0; i<len;++i)
	{
	  arr1[i]=0;
	  arr2[i]=0;
	    
	}
	
	vector<int>::iterator indx= input1.begin();
	for(int i=0; i<len;++i)
	{
	    /*if( std::binary_search(input1.begin(),input1.end(),input2[i]) )
	        {
	            arr1[i]= 1;
	            arr2[i]=1;
	               
	        }*/

		vector<int>::iterator indx=lower_bound(input1.begin(),input1.end(), input2[i]);
		int pos=indx-input1.begin();
		if(!  (indx == input1.end() || *indx!=input2[i])     )
		{
			    arr1[pos]= 1;
	            arr2[i]=1;
		}
	}
	
	for(int i=0; i<len;++i)
	{
	  if( arr1[i]== 0)
	  ss<<std::to_string(input1[i])<<'$';
	  if( arr2[i]== 0)
	  ss<<std::to_string(input2[i])<<'$';
	    
	}
	
	
	delete [] arr1;
	delete [] arr2;
	
	string output =  ss.str();
	output.pop_back();
	return   output;
}


int main() {
    string output;
    int ip1_size = 0;
    cin >> ip1_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> ip1;
    int ip1_item;
    for(int ip1_i=0; ip1_i<ip1_size; ip1_i++) {
        cin >> ip1_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        ip1.push_back(ip1_item);
    }
    int ip2_size = 0;
    cin >> ip2_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> ip2;
    int ip2_item;
    for(int ip2_i=0; ip2_i<ip2_size; ip2_i++) {
        cin >> ip2_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        ip2.push_back(ip2_item);
    }
    output = uncommonBetweenCommon(ip1,ip2);
	
    cout << output << endl;
    return 0;
}
