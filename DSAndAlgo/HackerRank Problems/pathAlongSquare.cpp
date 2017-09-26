#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <set>
#include<map>
#include<algorithm>


using namespace std;
struct cord{
    int x;
    int y;
    cord(int x , int y)
    {
       this->x=x;
        this->y=y;
    }
};
bool compareX(cord& a, cord& b)
{
	return a.x <b.x;
}

bool compareY(cord& a, cord& b)
{
	return a.y <b.y;
}
int dist(cord& a, cord& b , int n)
{
	if((a.x ==0 && b.x == n)||( a.x==n && b.x ==0))
		return a.y+b.y+n;
	if((a.y ==0 && b.y==n)||(a.y==n && b.y ==0))
	   return a.x+b.x+n;

    return (abs(a.x-b.x) +abs (a.y-b.y));
    
}
bool compareClockWise(cord& a, cord& b)
{
	/*
    if (a.x - x >= 0 && b.x - x < 0)
        return true;
    if (a.x - x < 0 && b.x - x >= 0)
        return false;
    if (a.x - x == 0 && b.x - x == 0) {
        if (a.y - y >= 0 || b.y - y >= 0)
            return a.y > b.y;
        return b.y > a.y;
    }*/

    // compute the cross product of vectors (center -> a) x (center -> b)
    int det = (a.x ) * (b.y ) - (b.x ) * (a.y );
    if (det < 0)
        return true;
    if (det > 0)
        return false;

    // points a and b are on the same line from the center
    // check which point is closer to the center
    int d1 = (a.x  ) * (a.x ) + (a.y ) * (a.y);
    int d2 = (b.x ) * (b.x ) + (b.y) * (b.y );
    return d1 > d2;
}


int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector<cord> plugs[4];
        for(int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        cin >> x >> y;
		if(x==0)
            plugs[3].push_back(cord(x,y));
		else if(y==0)
			plugs[0].push_back(cord(x,y));
		else if(x == n)
			plugs[1].push_back(cord(x,y));
		else if(y ==n)
		{
			 plugs[2].push_back(cord(x,y));
		}

    }
    // Write Your Code Here
    int curMin=0,globalMin=INT_MAX;
	sort(plugs[0].begin(),plugs[0].end(),compareX);
	sort(plugs[1].begin(),plugs[1].end(),compareY);
	sort(plugs[2].rbegin(),plugs[2].rend(),compareX);
	sort(plugs[3].rbegin(),plugs[3].rend(),compareY);
	vector<cord> sorted;
	for (int i = 0; i < 4; i++)
	{
		
		sorted.insert(i==0?sorted.begin():sorted.end(),plugs[i].begin(),plugs[i].end());
		plugs[i].clear();
	}
	int* arr = new int[m];
	int dst=0;
	for(int i =0 ; i <m ; ++i)
    {
		if(i == m-1)
		{
			dst = dist(sorted[i],sorted[0],n);
			arr[i]= min(dst,4*n-dst);
		}
		else		
		{
			dst= dist(sorted[i],sorted[i+1],n);
			arr[i]= min(dst,4*n-dst);
		}
	}
	  
        
        for(int j=0; j<k-1 ;++j)
		{
            curMin+=arr[j];   
            
            
        }
        
		globalMin=min(globalMin,curMin);
		curMin -=arr[0];
		int j =0;
		for (int i = 1; i < m; i++)
		{
			
			curMin +=arr[(i+k-2)%m];
			globalMin=min(globalMin,curMin);
			curMin-=arr[i];

		}
	
	delete[] arr;
    cout<<globalMin;
    
    return 0;
}