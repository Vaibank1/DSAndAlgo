#include<iostream>
#include<vector>

using namespace std;

/*
* Definition for binary tree
*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void BST(TreeNode* root, int& node1, int& node2, int max, int min)
{

	if (NULL == root)
		return;
	if (node1 != -1 && node2 != -1)
		return;
	if (root->val <min || root->val>max || (root->left&& root->left->val > root->val)
		|| (root->right && root->right->val < root->val))
	{
		if (node1 == -1)
			node1 = root->val;
		else
			node2 = root->val;
	}
	BST(root->left, node1, node2, root->val, min);
	BST(root->left, node1, node2, max, root->val);

}

vector<int> recoverTree(TreeNode* A) {
	int n1 = -1, n2 = -1, min = INT_MIN, max = INT_MAX;
	BST(A, n1, n2, max, min);
	return vector<int> {n1, n2};

}


void SumBST(TreeNode* root, int sum, int& curSum, vector<vector<int> > ans, vector<int>& curPath)
{

	if (NULL == root)
		return;
	curSum += root->val;
	curPath.push_back(root->val);
	if (curSum == sum)
	{
		ans.push_back(curPath);
	}

	BST(root->left, sum, curSum, ans, curPath);
	BST(root->right, sum, curSum, ans, curPath);

	curSum -= root->val;
	curPath.pop_back();

}
vector<vector<int> > pathSum(TreeNode* A, int B) {
	vector<vector<int> > ans;
	vector<int> path;
	int sum = 0;
	SumBST(A, B, sum, ans, path);
	return ans;
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	recoverTree(root);

	return 0;
}
