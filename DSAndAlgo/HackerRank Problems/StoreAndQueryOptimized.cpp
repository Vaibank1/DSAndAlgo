#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

  
    //tables to store data 
//at 0 position we store the sum of all the array.
int DPCSR[101][11][5][8][26]={0};
  int DPCS[101][11][5][8]={0};
  int DPSR[101][11][8][26]={0};
  int DPS[101][11][8]={0};

 

void Split(char *d, int &D1, int &D2)
{
  char a[4],b[4];
  D1=0;D2=0;
  for(int j=0; j<7; j++)
  {
    if(d[j]!='.' && d[j]!='\0')
      a[j]=d[j];
    else
    {
      a[j]='\0';
      D1=stoi(a);
      if(d[j]=='.')
        D2=stoi(&(d[j+1]));
      else
        D2=0;
      break;
    }
  }
  
} 


int main() {
  int N;
  
  int D1, D2, P, C, S, R;
  cin >> N;
  int day=0;
  int productID=0;
  int catID=0;
  int stateID=0;
  int regionID=0;
  int dayStart=0,dayEnd=0;
  char typeOfInput=0;
  char input[10] ;
  char *token =0;  
    
    long unsigned int result=0;
  for(int i=1; i<=N; i++)
  {

    cin>>typeOfInput;
	if(typeOfInput == 'Q' || typeOfInput == 'q')
	{
			result=0;
		
		cout<<endl;
		
			//day
		cin>>input;
		Split(input, dayStart, dayEnd);
	
		cin >> input;
		Split(input, productID, catID);
		cin >> input;	
		Split(input, stateID, regionID); 
		if(regionID!=0 &&  catID !=0 && productID != -1 && stateID != -1)
		{
			//we have complete query
			if(dayEnd==0)
				cout<< DPCSR[dayStart][productID][catID][stateID][regionID];
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					result +=DPCSR[i][productID][catID][stateID][regionID];
				}
				cout<<result;
			}
		}
		//case 2: region is optional 
		else if( regionID ==0 &&  catID !=0 && productID != -1 && stateID != -1 )
		{
			if(dayEnd == 0)
			{
				cout<< DPCS[dayStart][productID][catID][stateID];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					result += DPCS[i][productID][catID][stateID];
				}
				cout<<result;
			}

		}
		//case 3 category is optional
		else if(regionID!=0 &&  catID ==0 && productID != -1 && stateID != -1)
		{
			if(dayEnd == 0)
			{
				cout<< DPSR[dayStart][productID][stateID][regionID];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					result += DPSR[i][productID][stateID][regionID];
				}
				cout<<result;
			}
		
		}

		//case 4 both region and category are optional
		else if(regionID == 0 &&  catID ==0 && productID != -1 && stateID != -1)
		{
			if(dayEnd == 0)
			{
				cout<< DPS[dayStart][productID][stateID];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					result += DPS[i][productID][stateID];
				}
				cout<<result;
			}
		
		}
		//case 5 productID is -1 and region is given
		else if( productID == -1 && stateID != -1 && regionID !=0)
		{
			if(dayEnd == 0)
			{
				for(int x=1; x<=10; x++) //product
				result += DPSR[dayStart][x][stateID][regionID];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					for(int x=1; x<=10; x++) //product
						result += DPSR[i][x][stateID][regionID];
				}
			}
				cout<<result;
			
		
		}
		//case 6 productID is -1 and region is optional
		else if( productID == -1 && stateID != -1 && regionID == 0 )
		{
			if(dayEnd == 0)
			{
				for(int x=1; x<=10; x++) //product
				result += DPS[dayStart][x][stateID];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					for(int x=1; x<=10; x++) //product
						result += DPS[i][x][stateID];
				}
			}
				cout<<result;
			
		
		}
		//case 7 stateID is -1 and catID is optional
		else if( productID != -1 && stateID == -1 && catID==0)
		{
			if(dayEnd == 0)
			{
			 
              for(int y=1; y<=7; y++)//state
                result += DPS[dayStart][productID][y];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					for(int y=1; y<=7; y++)//state
						result += DPS[i][productID][y];
				}
			}
				cout<<result;
			
		
		}

		//case 8 stateID is -1 and catID is given
		else if( productID != -1 && stateID == -1 && catID!=0)
		{
			if(dayEnd == 0)
			{
				for(int y=1; y<=7; y++)//state
					result +=  DPCS[dayStart][productID][catID][y];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					for(int y=1; y<=7; y++)//state
						result +=  DPCS[i][productID][catID][y];
					
				}
				
			}
			cout<<result;
		
		}
		//case 9 productID not = -1 and stateID is -1
		else if( productID != -1 && stateID == -1 && catID ==0 &&  regionID==0)
		{
			if(dayEnd == 0)
			{
				//for(int y=1; y<=7; y++)//state
					result = DPS[dayStart][productID][0];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					//for(int y=1; y<=7; y++)//state
						result += DPS[i][productID][0];
				}
				
			}
			cout<<result;
		
		}

		//case 8 productID == -1 and stateID == -1 
		else if( productID == -1 && stateID == -1)
		{
			if(dayEnd == 0)
			{
				//for(int x=1; x<=10; x++) //product
    //          for(int y=1; y<=7; y++)//state
    //            result += DPS[dayStart][x][y];
				result = DPS[dayStart][0][0];
			}
			else
			{

				for(int i = dayStart; i<= dayEnd;++i)
				{
					
							result += DPS[i][0][0];
				}
			}
				cout<<result;
			
		
		}
		cout<<endl;
	}

	else if(typeOfInput == 'S' || typeOfInput == 's')
	{

		//store the data
		
		
		catID=0;;regionID=0;
			//day
		cin>>day;
	
		cin >> input;
		Split(input, productID, catID);
		cin >> input;	
		Split(input, stateID, regionID); 
		
		

		if(regionID ==0 && catID==0)
		{			
			DPS[day][productID][stateID]++;
			DPS[day][productID][0]++;
			DPS[day][0][stateID]++;
			DPS[day][0][0]++;
		}
		else if(catID==0 && regionID !=0 )
		{
 			DPSR[day][productID][stateID][regionID]++;			

			DPS[day][productID][stateID]++;
			DPS[day][productID][0]++;
			DPS[day][0][stateID]++;
			DPS[day][0][0]++;
		}
		else if(regionID==0 && catID!=0)
		{
			DPCS[day][productID][catID][stateID]++;

			DPS[day][productID][stateID]++;
			DPS[day][productID][0]++;
			DPS[day][0][stateID]++;
			DPS[day][0][0]++;
		}

		else
		{
			DPCSR[day][productID][catID][stateID][regionID]++;
			DPCS[day][productID][catID][stateID]++;
			DPSR[day][productID][stateID][regionID]++;

			DPS[day][productID][stateID]++;
			DPS[day][productID][0]++;
			DPS[day][0][stateID]++;
			DPS[day][0][0]++;
			

		}


	}

  } 


  getchar();
}