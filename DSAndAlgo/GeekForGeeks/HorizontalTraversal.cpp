 

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <queue>
#include "Node.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <map>
using namespace std;




map<int,vector<Node*>> order;

void horizontalTraverse(Node* root, int hd)
{
	if(root == nullptr)
		return;
	order[hd].push_back(root);
	horizontalTraverse(root->left,hd-1);
	horizontalTraverse(root->right,hd+1);

}

void print(Node* root)
{
	if(root == nullptr)
		return;
	map<int,vector<Node*>>::iterator it= order.begin();

	for (it; it != order.end(); it++)
	{
		cout<<it->first<<'\t';
		for(int i=0; i< it->second.size();++i)
		{
			cout<<it->second[i]->data<<'\t';
		}
		cout<<endl;
	}

}

int main()
{
	{
		struct Node *root = newNode(1);
		root->left = newNode(2);
		root->right = newNode(3);
		root->left->left = newNode(4);
		root->left->right = newNode(5);
		horizontalTraverse(root, 0);
		print(root);

		deleteTree(root);


		order.clear();
	}
_CrtDumpMemoryLeaks();	
	return 0;
}