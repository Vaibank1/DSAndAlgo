#include "stdafx.h"
#include "Node.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <queue>
#include <array>
#include <list>




using namespace std;

template<typename T>
int countLen(const shared_ptr<Node<T>>& root)
{
	shared_ptr<Node<T>> r=root;
	int count = 0;
	while (r!=nullptr)
	{
		count++;
		r = r->next;

	}
	return count;
}


template<typename T>
void detectOverLap(const shared_ptr<Node<T>>& head1, const shared_ptr<Node<T>>& head2)
{
	
	int count1 = countLen(head1),count2= countLen(head2);
	int diff = abs(count1 - count2);
	shared_ptr<Node<T>> l1 = head1;
	shared_ptr<Node<T>> l2 = head2;
	while (diff--)
	{
		count1 > count2 ? l1 = l1->next : l2 = l2->next;
	}
	while (l1 != l2 && l1!=nullptr && l2 != nullptr)
	{
		l1 = l1->next;
		l2 = l2->next;

	}
	if (l1 != nullptr)
		std::cout << l1->data;
	else 
		std::cout << "No Overlap";


}

int main()
{

	{

		//list l1
		std::shared_ptr<Node<char>> l1 = std::make_shared<Node<char>>('A');
		(*l1).next = make_shared<Node<char>>('B');
		(*l1).next->next = make_shared<Node<char>>('C');
		l1->next->next->next = make_shared<Node<char>>('D');
		l1->next->next->next->next = nullptr;
		//list l2 //overlapping with L1
		std::shared_ptr<Node<char>> l2 = std::make_shared<Node<char>>('E');
		l2->next = make_shared<Node<char>>('F');
		l2->next->next = l1->next->next;
		
		detectOverLap(l1, l2);
		
		
	}

	_CrtDumpMemoryLeaks();
	return 0;
}

