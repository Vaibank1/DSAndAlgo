#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

struct Order
{
	unsigned long long int arrivalTime;
	unsigned long long int cookingTime;

	Order()
	{
		arrivalTime=0;
		cookingTime=0;
	}

};

bool compare(Order& a , Order& b)
{
	return a.arrivalTime < b.arrivalTime;
}


bool compareWait(Order& a , Order& b)
{
	return a.cookingTime > b.cookingTime;
}



int main() {
    
	vector<Order> orderList;
	int numOfOrders=0;
	cin>>numOfOrders;
	unsigned long long int  curTime=0;
	unsigned long long int  waitingTime=0;
	for(int i =0; i< numOfOrders; ++i)
	{
		Order order;
		cin>>order.arrivalTime>>order.cookingTime;
		orderList.push_back(order);
	}

	sort(orderList.begin(),orderList.end(),compare);

	priority_queue<Order,vector<Order>,function<bool(Order&,Order&)>> queue(compareWait);
	
	for(int i =0 ; i< numOfOrders; ++i)
	{

		//add
		Order& a =  orderList[i];
		
		if(i==0|| curTime >= a.arrivalTime)
		{
				queue.push(a);
				curTime = max(curTime,a.arrivalTime);

		}


		else if(queue.empty() == false)
		{
			//its time to process and serve the orders
			while (queue.empty() == false && a.arrivalTime > curTime)
			{				
				curTime += queue.top().cookingTime;
				waitingTime += curTime-queue.top().arrivalTime;
				queue.pop();
				//cout<<curTime<<endl;

			}
			queue.push(a);
			curTime = max(curTime,a.arrivalTime);
		}
	}

	while(queue.empty()==false)
	{
		curTime += queue.top().cookingTime;
		waitingTime += curTime-queue.top().arrivalTime;
				queue.pop();

		//cout<<curTime<<endl;
	}

	
	waitingTime/=numOfOrders;
	cout<<waitingTime<<endl;
		
	
	
    return 0;
}
