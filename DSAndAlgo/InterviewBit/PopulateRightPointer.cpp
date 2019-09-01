
#include<iostream>
using namespace std;


/**
* Definition for binary tree with next pointer.*/
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };



void connect(TreeLinkNode* A) {

	TreeLinkNode* pre = NULL, *leftWall = NULL, *cur = A;

	while (cur)
	{
		while (cur)
		{
			if (cur->left)
			{
				if (pre)
				{
					pre->next = cur->left;
				}
				else
				{
					leftWall = cur->left;
				}
				pre = cur->left;
			}

			if (cur->right)
			{
				if (pre)
				{
					pre->next = cur->right;
				}
				else
				{
					leftWall = cur->right;
				}
				pre = cur->right;
			}
			cur = cur->next;
		}

		cur = leftWall;
		pre = NULL;
		leftWall = NULL;

	}





}


int main()
{
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right= new TreeLinkNode(3);

	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);

	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);


	root->left->left->left= new TreeLinkNode(8);
	root->left->left->right = new TreeLinkNode(9);

	root->left->right->left = new TreeLinkNode(10);
	root->left->right->right = new TreeLinkNode(11);



	root->right->left->left = new TreeLinkNode(12);
	root->right->left->right = new TreeLinkNode(13);



	root->right->right->left = new TreeLinkNode(14);
	root->right->right->right = new TreeLinkNode(15);




	connect(root);

	TreeLinkNode* tmp = root;
	int level = 1;
	while (tmp)
	{
		cout << "Level " << level<<"\t";
		

		TreeLinkNode* next = tmp;
		while (next)
		{
			cout << next->val << " ";
			next = next->next;
		}
		cout << endl;

		level++;
		tmp = tmp->left;
	}

	return 0;
}
