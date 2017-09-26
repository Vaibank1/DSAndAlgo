
#include"Node.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

template<typename T>
void print(shared_ptr<Node<T>> root)
{
	while (root)
	{
		cout << root->data<<'\t';
		root =root->next;
	}
	cout << endl;


}
template<typename T>
shared_ptr<Node<T>> reverse(const shared_ptr<Node<T>>& root)
{
	if (!root || !root->next)
		return root;
	shared_ptr<Node<T>> newHead = reverse(root->next);
	root->next->next = root;
	root->next = nullptr;
	return newHead;

}

//int main()
//{
//
//	{
//		shared_ptr<Node<int>> root = make_shared<Node<int>>(1);
//		root->next = make_shared<Node<int>>(2);
//		root->next->next = make_shared<Node<int>>(3);
//		root->next->next->next = make_shared<Node<int>>(4);
//		print(root);
//		
//		print(reverse(root));
//
//	
//	}
//	_CrtDumpMemoryLeaks();
//	return 0;
//}
