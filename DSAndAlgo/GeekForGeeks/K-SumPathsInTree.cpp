
#include "Node.h"
#include <vector>

using namespace std;


void print(vector<Node*>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout<<vec[i]->data<<"\t";

	}
	

}

int kSumPath(Node* root, vector<Node*>& parents , int sum , int k)
{
	int count(0);
	if(root == nullptr)
		return 0;
	if(root->data == k)
	{
			count++;
			cout<<"path\t"<<root->data<<endl;
	}
	else
	{
		sum += root->data;
		if(sum == k)
		{
			count++;			
			cout<<"path\t";print(parents); cout<<root->data<<endl;			

		}

		//check whether this node is in between a k-sum path, which does not start with root.
		int s=root->data;
		vector<Node*> temp;
		temp.push_back(root);
		for (int i = parents.size()-1; i >0; i--)
		{
			s+= parents[i]->data;
			temp.push_back(parents[i]);
			if( s == k)
			{
				count++;
				cout<<"path\t";print(temp); cout<<endl;			
			}
		}
		temp.clear();
	}
	parents.push_back(root);
	//check for childs 
	count+=kSumPath(root->left,parents,sum,k);

	count+=kSumPath(root->right,parents,sum,k);

	parents.pop_back();
	return count;
}



int main()
{

	//tree
	{
		Node* root = newNode(1);
		root->left = newNode(2);
		root->right = newNode(3);
		root->left->right = newNode(1);
		root->right->right = newNode(4);
		root->left->left = newNode(5);
		root->right->left = newNode(2);

		int k = 5;


		vector<Node*> vec;
		cout << "Total nunber of kSumPaths are : " << kSumPath(root, vec, 0, k);

		vec.clear();


		deleteTree(root);

	}
	_CrtDumpMemoryLeaks();	

	return 0;

}