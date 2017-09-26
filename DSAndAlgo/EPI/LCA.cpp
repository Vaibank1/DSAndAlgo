#include"Node.h"


template<typename T>
bool LCA(const shared_ptr<TreeNode<T>>& root ,T val1 , T val2)
{
	if (!root)
		return false;
	bool isFound = false;
	if (root->data == val1 || root->data == val2)
		isFound = true;
	bool lcaLeft = LCA(root->left, val1, val2);
	bool lcaRight = LCA(root->right, val1, val2);
	if (lcaLeft && lcaRight)
	{
		cout << "LCA is :" << root->data;
		return true;
	}
	else if (isFound && (lcaLeft || lcaRight))
	{
		cout << "LCA is :" << root->data;
		return true;
	}
	return (isFound || lcaLeft || lcaRight);


}

int main()
{
	
	{
		shared_ptr<TreeNode<int>> root = make_shared<TreeNode<int>>(1);
		root->left = make_shared<TreeNode<int>>(2);
		root->right = make_shared<TreeNode<int>>(3);
		root->left->left = make_shared<TreeNode<int>>(4);
		root->left->right = make_shared<TreeNode<int>>(5);

		root->right->left = make_shared<TreeNode<int>>(6);
		root->right->right = make_shared<TreeNode<int>>(7);
		
		LCA(root, 7, 15);
		cout << endl;



	}

}