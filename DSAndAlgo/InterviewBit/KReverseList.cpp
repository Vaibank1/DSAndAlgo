
#include<iostream>
using namespace std;

/* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverse(ListNode* root)
{
	ListNode* cur= root, *next, *prev = NULL;

	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;

	}
	return prev;

}

ListNode* reverseList(ListNode* A, int K) {
	
	ListNode * first, *last, *prev = new ListNode(0);
	prev->next = A;
	last = prev;
	if (K == 1)
		return A;
	ListNode* next,*newRoot=A;
	bool isFirst = false;
	while (last->next)
	{
		for (int i = 0; i < K; i++)
			last = last->next;
		if (!isFirst)
		{
			newRoot = last;
			isFirst = true;
		}

		first = prev->next;
		prev->next = NULL;

		next = last->next;
		last->next = NULL;
		last = reverse(first);

		prev->next = last;
		first->next = next;
		prev = last = first;
	}

	
	return newRoot;
	
}

int main()
{
	ListNode* root = new ListNode(6);
	root->next = new ListNode(10);
	root->next->next = new ListNode(0);
	root->next->next->next = new ListNode(3);
	root->next->next->next->next = new ListNode(4);
	root->next->next->next->next->next = new ListNode(8);

	reverseList(root,3);



	return 0;
}
