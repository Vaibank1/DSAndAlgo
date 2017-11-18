#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>

using namespace std;
struct Node
{
	shared_ptr<Node> left, right;
	int data;
	Node(int d) :data(d) {}
};

int maxSum( shared_ptr<Node> & root, int & result)
{
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return root->data;
	int ls = maxSum(root->left, result);
	int rs = maxSum(root->right, result);

	if (root->left && root->right)
	{
		result = max(result, ls + rs + root->data);

		return max(rs, ls) + root->data;

	}

	return root->left ? ls + root->data : rs + root->data;
	

}



int main()
{
	shared_ptr<Node> root = make_shared<Node>(-15);
	root->left = make_shared<Node>(5);
	root->right = make_shared<Node>(6);
	root->left->left = make_shared<Node>(-8);
	root->left->right = make_shared<Node>(1);
	root->left->left->left = make_shared<Node>(2);
	root->left->left->right = make_shared<Node>(6);
	root->right->left = make_shared<Node>(3);
	root->right->right = make_shared<Node>(9);
	root->right->right->right = make_shared<Node>(0);
	root->right->right->right->left = make_shared<Node>(4);
	root->right->right->right->right = make_shared<Node>(-1);
	root->right->right->right->right->left = make_shared<Node>(10);

	int res = INT_MIN;
	maxSum(root, res);
	cout << "Max pathSum of the given binary tree is "
		<< res;

	return 0;
}