#include"Node.h"
#include<array>

using namespace std;



array<int,11> inOrder = { 5,4,3,2,1,11,7,10,8,9,6 };
array<int, 11> postOrder = { 3,4,5,2,11,10,9,8,6,7,1 };


template<typename T, size_t N>
T findIndex(const array<T, N> & arr, int val)
{
	/*for (int i = 0; i < arr.size(); ++i)
	{
	if (arr[i] == val)
	return i;
	}*/

	int i = find(arr.begin(), arr.end(), val) - arr.begin();
	return i;
}


Node* CreateTree(int& postOrderRoot, int inOrderStart, int inOrderEnd)
{
	if (inOrderStart > inOrderEnd)
		return nullptr;
	//take a root from postOrder
	Node* root =newNode(postOrder[postOrderRoot--]);
	if (inOrderStart == inOrderEnd)
		return root;
	int x = findIndex(inOrder, root->data);
	

	root->right = CreateTree(postOrderRoot, x + 1, inOrderEnd);
	root->left = CreateTree(postOrderRoot, inOrderStart, x - 1);
	
	return root;
}


int main()
{

	int p = (int)postOrder.size() - 1;
	Node* root = CreateTree(p, 0, (int)inOrder.size() - 1);


	return 0;
}