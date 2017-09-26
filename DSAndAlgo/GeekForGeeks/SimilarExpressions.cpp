

#include "stdafx.h"
#include <iostream>
#include <vector>

#include <conio.h>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;




string  removeBraces(const string& input)
{
	string str(input);
	char lastSign=' ';
	bool bracesStart=false,bracesClosed=false;
	int j=0;
	for(int i=0;i<str.length();++i)
	{
		if(str[i] =='(')
		{
			bracesStart = true;
			bracesClosed = false;
			
			str[i] = ')';
			
			
		}
		else if(str[i] ==')')
		{
			bracesStart = false;
			bracesClosed = true;
			lastSign = ' ';
		}
		else if(str[i] == '-' || str[i] == '+')
		{
		   if(bracesStart == true && bracesClosed == false && lastSign !=' ')
		   {
			   if(lastSign == '-')
			  {
				  if(str[i]=='-')
					str[i] = '+';
				  else 
					  str[i]=lastSign;

			   }			   
			
		   }
		   else if (bracesStart == false )		
			lastSign = str[i]; 		   
		 
		}
		
		

		
	}

	str.erase(std::remove(str.begin(),str.end(),')'),str.end() );
	
	return str;
}



void check(const string& str1, int coef[26] ,int sign[26] )
{
	
	int len = str1.length();
	//int coef[26]={0};
	//int sign[26]={0};//0 means positive , -1 means negative
	
	//first is always an operand
	for(int i = 0; i<len;i+=2)
	{
		if(coef[str1[i+1]- 'a'] == 0)
			coef[str1[i+1]- 'a']+=1 ;
		else 
		{
			//we need to look at the last sign 
			if(sign[str1[i+1]- 'a'] >=0)
			{
				//last sign was positive
				if(str1[i] == '-')
					coef[str1[i+1]- 'a']-=1 ;
				else 
					coef[str1[i+1]- 'a']+=1 ;

			}
			else 
			{
				//last sign was negative
				if(str1[i] == '-')
					coef[str1[i+1]- 'a']+=1 ;
				else 
					coef[str1[i+1]- 'a']-=1 ;


			}
		}
		if(str1[i] == '+')
			sign[str1[i+1]- 'a'] +=1;
		else 
			sign[str1[i+1]- 'a'] -=1;
	}

	


}

bool compare(const string& str1, const string& str2)
{

	int coef1[26]={0};
	int sign1[26]={0};
	check(str1,coef1,sign1);



	int coef2[26]={0};
	int sign2[26]={0};
	check(str2,coef2,sign2);
	bool res = true;
	for(int i =0; i<26;++i)
		if((coef1[i] != coef2[i]) || (sign1[i] != sign2[i]))
		{
				res = false;
				break;
		}


return res;
}


string checkExp(const string& str1,const string& str2)
{
	string res= "NO";
	//remove braces
	string expr1 =  removeBraces(str1) ;
	string expr2 =  removeBraces(str2);
	
	if(expr1 == expr2)
		res = "YES";
	else 
	{
		if(expr1[0] != '+' && expr1[0] != '-')
		expr1 = '+' + expr1;
		if(expr2[0] != '+' && expr2[0] != '-')
		expr2 = '+' + expr2;

		//check if ordering of the variables are diffe. but sign is same
		if( compare(expr1,expr2))
			res = "YES";
	}

		
	return res;

}
//
//
//string checkExp(const string& str1, const string& str2)
//{
//	int coef[26]={0};
//	int sign[26]={0};//0 means positive , -1 means negative
//	int currentSign=' ';
//	for (int i = 0; i < str1.length(); i++)
//	{
//		if(str1[i]== '+' || str1[i]== '-')
//		{
//			currentSign = str1[i];
//		}
//		
//
//	}
//
//}

int main() {
	//code


	int T;
	cin>>T;
	for(int i =0; i <T ; ++i)
	{
	    string str1,str2;
	    cin>>str1>>str2;
		cout<<checkExp(str1,str2);
	 
	}
	_getch();
	return 0;
}