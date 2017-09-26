#include"Node.h"
#include<array>

using namespace std;

array<int, 4> inOrder = { 3,4,2,1 };
array<int, 4> postOrder = { 4,3,2,1 };

template<typename T,size_t N>
T findIndex(const array<T, N> & arr, int val)
{
	/*for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == val)
			return i;
	}*/

	int i =  find(arr.begin(), arr.end(), val) - arr.begin();
	return i;
}


shared_ptr<TreeNode<int>> CreateTree( int postOrderRoot , int inOrderStart, int inOrderEnd)
{
	if (inOrderStart > inOrderEnd)
		return nullptr;
	//take a root from postOrder
	shared_ptr < TreeNode<int>> root = make_shared<TreeNode<int>>(postOrder[postOrderRoot--]);
	if (inOrderStart == inOrderEnd)
		return root;
	int x = findIndex(inOrder, postOrder[postOrderRoot]);
	
	root->right = CreateTree(postOrderRoot, x + 1, inOrderEnd);
	root->left= CreateTree(postOrderRoot,inOrderStart,x-1);
}


int main()
{
	{
		int x = postOrder.size() - 1;
		shared_ptr<TreeNode<int>> root = CreateTree(x, 0, (int)inOrder.size() - 1);

	}


	return 0;
}