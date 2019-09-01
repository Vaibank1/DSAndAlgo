#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>

#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
using namespace std;


template<typename T>
struct  TreeNode
{
	T key;
	std::shared_ptr<TreeNode<T>> left, right;
	TreeNode(const T& a) :key(a), left(nullptr), right(nullptr),rank(0) {}
	int rank;

};

template<typename T>
void IncreaseRank(shared_ptr<TreeNode<T>>& root)
{
	if (root)
	{
		root->rank++;
		IncreaseRank(root->left);
		IncreaseRank(root->right);
	}

	
}
template<typename T>
bool checkDup(T key, shared_ptr<TreeNode<T>>& root)
{
	if (!root)
		return false;
	if (root->key == key)
		return true;
	return checkDup(key, root->left) || checkDup(key,root->right);


}

template<typename T>
void InsertInBST(T key, shared_ptr<TreeNode<T>>& root,int rank=0)
{
	
	if (root == nullptr)
	{
		root =  make_shared<TreeNode<T>>(key);
		root->rank = rank;
		return;
	}
	
	
	if ((root)->key > key)
	{
		
		InsertInBST(key,(root)->left, (root)->rank);
		IncreaseRank(root->right);
		root->rank++;

	}
	else
	{
		InsertInBST(key,(root)->right,root->rank+1);
		
	}
}

template<typename T>
void InorderTraversal(shared_ptr<TreeNode<T>>& root)
{
	if (root == nullptr)
		return;
	InorderTraversal(root->left);
	cout << root->key << ' ' << root->rank << endl;
	InorderTraversal(root->right);

}

map<int, vector<shared_ptr<TreeNode<int>>>> mp;
template<typename T>
void VerticalTraversal(shared_ptr<TreeNode<T>>& root, int vNum)
{
	if (root == nullptr)
		return;
	mp[vNum].push_back(root);
	VerticalTraversal(root->left, vNum - 1);
	VerticalTraversal(root->right, vNum + 1);
}

template<typename T>
void HorizontalTraversal(shared_ptr<TreeNode<T>>& root, int vNum)
{
	if (root == nullptr)
		return;
	mp[vNum].push_back(root);
	HorizontalTraversal(root->left, vNum + 1);
	HorizontalTraversal(root->right, vNum + 1);
}

shared_ptr<TreeNode<int>>  CreateTree()
{

	int N = 20 ;

	shared_ptr<TreeNode<int>> root = nullptr;
	for (int i = 0; i < N; i++)
	{
		int num = (rand() )%N +(1);
		if(!checkDup(num, root) )
			InsertInBST(num, root);

	}
	

	

	HorizontalTraversal(root, 0);

	for (auto it : mp)
	{
		//cout << "Level : " << it.first << '\n';
		for (auto i : it.second)
		{
			cout << i->key << ' ' /*<< i->rank << ' '*/;
		}
		cout << endl;
	}

	return root;

}

int getRank(int num, shared_ptr<TreeNode<int>>& root)
{
	if (root == nullptr)
		return 0;
	if (root->key == num)
		return root->rank;
	
	int rnk = root->rank;	
	if (num > root->key)
		rnk = getRank(num, root->right);
	else
		rnk = getRank(num, root->left);
	if (rnk == 0)
	{
		if (num < root->key)
			rnk = root->rank-1;
		else 
			rnk = root->rank +1;

	}
	return rnk;
	
}

int RangeSearch(int start, int end, shared_ptr<TreeNode<int>>& root)
{
	
	return getRank(end,root) - getRank(start,root) ;

}

int main()
{
	mp.clear();
	shared_ptr<TreeNode<int>> root = CreateTree();
	cout << endl;
	cout<< RangeSearch(3,5,root)<<endl;

	cout << RangeSearch(0,11, root) << endl;

	cout << RangeSearch(1,10, root) << endl;



	return 0;

}