#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <set>
#include<map>

using namespace std;





unsigned long long  Vhash(vector<int> freq)
{
    unsigned long long t=1,ret=0;
    for(int i=0; i<26; i++)
    {
        ret += t*freq[i];
        t=t*(unsigned long long )1000003;
    }
    return ret;
}




unsigned int sherlockAndAnagrams(string s){
    // Complete this function
	int length = s.length();
	unsigned int anagramCount =0;
	unsigned int temp =0;
	std::map<unsigned long long,int> list;

	//create each sub string and store 
	for(int i=0; i <length; ++i)
	{
		vector<int> freq(26);
		fill(freq.begin(),freq.end(),0);
		for(int j =i; j<length;++j)
		{
		
			freq[s[j]-'a']++;
			list[Vhash(freq)]++;
		}
	}
		

	for(std::map<unsigned long long,int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		temp = (it->second*(it->second-1))/2;
		anagramCount += temp;
	}



	return anagramCount;

}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = sherlockAndAnagrams(s);
        cout << result << endl;
    }
    return 0;
}