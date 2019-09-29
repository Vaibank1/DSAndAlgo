

#include <vector>
#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>
#include <climits>

//#include <cstring>

using namespace std;

//create a segement tree for RMQ
#define MAX 10


int searchRange(int low,int high, int* segTree, int start,int end, int pos)
{
	//anw the query for low to high.
	//i.e. min between range [low,high] in segtree
	
	if(start > end)
		return INT_MAX;

	//out of range of this node of segTree
	if(high < start || low > end)
		return INT_MAX;
	//exact match
	if(low == start && end == high)
	{
		return segTree[pos];
	}
	//if this is the leaf node
	if(start == end)
	{
		return segTree[pos];
	}

	//in between the current range of this node	
	
	int left ,right,mid;
	//search both half
	mid = (start+end)/2;
	left = searchRange(low,high,segTree,start,mid,2*pos+1);
	
	 right = searchRange(low,high,segTree,mid+1,end,2*pos+2);
	
	return min(left,right);
	
}


void createSegTree(int*segTree,int* arr,int low,int high,int pos)
{
	if(high == low)
	{
		segTree[pos]=arr[low];
		return;
	}
	int mid = (low+ high)/2;
	 createSegTree(segTree, arr, low,mid, pos*2 +1);
	 createSegTree(segTree, arr, mid+1,high, pos*2 +2);
	 segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);	
	
}
int main()
{

	int arr[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = std::rand()%99 +1 ;

	}

	int x = ceil(log(MAX)/log(2));
	

	int* segTree = new  int [2*(int)pow(2,x)-1];

	createSegTree(segTree,arr,0,MAX-1,0);

	int ans = searchRange(1,2,segTree,0,MAX-1,0);

	delete[] segTree;

return 0;
}