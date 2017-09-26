

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <queue>
#include "Node.h"

using namespace std;


int height(Node* root)
{
	if(root == nullptr)
		return 0;
	int lHeight= height(root->left);
	int rHeight= height(root->right);
	
	return lHeight>rHeight? lHeight+1:rHeight+1;

}

void levelOrderRecurse(Node* root, int level)
{
	if(root == nullptr)
		return;
	if(level == 1)
		cout<<root->data<<'\t';
	else 
	{
		levelOrderRecurse(root->left,level -1);
		levelOrderRecurse(root->right,level -1);

	}

}

void levelOrderTraverse(Node* root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		levelOrderRecurse(root,i);
		cout<<endl;

	}
}


void levelOrderByQueue(Node * root)
{
	if(root == nullptr)
		return;
	queue<Node*> listFIFO;
	
	listFIFO.push(root);

	Node* temp;
	while(!listFIFO.empty() )
	{
		temp = listFIFO.front();
		listFIFO.pop();
		cout<< temp->data<<"\t";
		if(temp->left)
			listFIFO.push(temp->left);
		if(temp->right)
			listFIFO.push(temp->right);


	}


}



int main()
{
	  struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

	levelOrderTraverse(root);
	//levelOrderByQueue(root);
		return 0;
}