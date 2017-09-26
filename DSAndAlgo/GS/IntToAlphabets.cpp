#include "stdafx.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>


bool isValid(int i, const std::string str,int& val)
{
	if(i +1 >=str.length())
		return false;
	char ch= str[i];
	 val= std::atoi(&ch);
	val=val*10;
	ch = str[i+1];
	val+= std::atoi(&ch);
	if(val <=0 || val>26)
		return false;
	return true;
}



int recurse(int index, std::string& output, const std::string input)
{
	int count1=0,count2=0;
	if(index == input.length())
	{
		std::cout<<output<<'\t';
		return 1;
	}
	if(input[index]=='0')
		return 0;
	
	output.push_back(input[index]-'0'+'A'-1);
	count1 = recurse(index+1,output,input);
	output.pop_back();
	
	int val=0;
	if(isValid(index,input,val))
	{
		output.push_back(val+'A'-1);
		count2 = recurse(index+2,output,input);
		output.pop_back();
	
	}
	return count1+count2;
}











int main()
{
	std::string str("0101"),output("");
	std::cout<<recurse(0,output,str);
	return 0;

}