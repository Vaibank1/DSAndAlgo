#include"Node.h"
#include <stack>
using namespace std;


template<typename T>
shared_ptr<TreeNode<T>> predecessor(const shared_ptr<TreeNode<T>>& root)
{
	shared_ptr<TreeNode<T>> cur = root, pre = root->left;
	while (pre->right && pre->right != cur)
	{
		pre = pre->right;
		
	}
	return pre;
}



template<typename T>
void Inorder(const shared_ptr<TreeNode<T>>& root)
{
	shared_ptr<TreeNode<T>> current  = root;
	while (current)
	{
		if (!current->left)
		{
			cout << current->data << '\t';
			current = current->right;
		}
		else
		{
			shared_ptr<TreeNode<T>> pre = predecessor(current);
			if (pre->right)
			{
				pre->right = nullptr;
				cout << current->data << '\t';
				current = current->right;
			}
			else
			{
				pre->right = current;
				current = current->left;
			}

		}

	}


}


template<typename T>
void Preorder(const shared_ptr<TreeNode<T>>& root)
{
	shared_ptr<TreeNode<T>> current = root;
	while (current)
	{
		if (!current->left)
		{
			cout << current->data << '\t';
			current = current->right;
		}
		else
		{
			shared_ptr<TreeNode<T>> pre = predecessor(current);
			if (pre->right)
			{
				pre->right = nullptr;
				
				current = current->right;
			}
			else
			{
				cout << current->data << '\t';
				pre->right = current;
				current = current->left;
			}

		}

	}


}



int main()
{
	{
		shared_ptr<TreeNode<int>> root = make_shared<TreeNode<int>>(4);
		root->left = make_shared<TreeNode<int>>(2);
		root->right = make_shared<TreeNode<int>>(6);
		root->left->left = make_shared<TreeNode<int>>(1);
		root->left->right = make_shared<TreeNode<int>>(3);

		root->right->left = make_shared<TreeNode<int>>(5);
		root->right->right= make_shared<TreeNode<int>>(7);
		Inorder(root);
		cout << endl;
		Preorder(root);


	}

	return 0;
}