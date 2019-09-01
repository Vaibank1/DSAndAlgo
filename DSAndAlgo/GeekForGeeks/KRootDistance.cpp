#include<iostream>
#include<conio.h>


using namespace std;

struct Tree {

	Tree* right, *left;
	int data;
	Tree(int d): data(d)
	{
		left = right = NULL;
	}

};


void printDown(Tree* node, int K)
{
	if (NULL == node)
		return;
	if (K == 0)
	{
		cout << node->data << " ";
		return;
	}

	printDown(node->left, K - 1);
	printDown(node->right, K - 1);


}


int printNode(Tree* root, int K, int target)
{
	if (root == nullptr)
		return -1;
	if (root->data == target)
	{
		printDown(root, K);
		return 0;
	}

	int dl = printNode(root->left, K, target);
	if (-1 != dl)
	{
		if (dl + 1 == K)
			cout << root->data << " ";
		else
			printDown(root->right, K - dl - 2);

			return K - dl - 1;
	}
	int dr = printNode(root->right, K, target);
	if (-1 != dr)
	{
		if (dr + 1 == K)
			cout << root->data << " ";
		else
			printDown(root->left, K - dr - 1);

		return K - dr - 2;
	}

	return -1;

}


int main()
{

	Tree* root = new Tree(10);
	root->left= new Tree(20);
	root->right = new Tree(30);

	root->left->left = new Tree(40);
	root->left->right = new Tree(50);

	root->right->left = new Tree(60);
	root->right->right = new Tree(70);


	printNode(root, 3, 20);
	return 0;
}
