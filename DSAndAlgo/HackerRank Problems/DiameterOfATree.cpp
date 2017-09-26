#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left, *right;

}Node;

int max(int a, int b)
{
	return a>b ? a : b;

}
void deleteNode(Node* root)
{
	if (!root)
		return;
	deleteNode(root->left);
	deleteNode(root->right);
	free(root);

}
void insertBST(Node** root, int n)
{
	if (*root == NULL)
	{
		*root = (struct node*)malloc(sizeof(Node));
		(*root)->data = n;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (n <= (*root)->data)
		insertBST(&((*root)->left), n);
	else
		insertBST(&((*root)->right), n);


}

int diameter(Node* root, int* h)
{
	if (!root)
	{
		*h = 0;
		return 0;
	}
	int h1 = 0, h2 = 0;
	int lDia = diameter(root->left, &h1);
	int rDia = diameter(root->right, &h2);

	*h = max(h1, h2) + 1;

	return max(h1+h2+1, max(lDia, rDia));


}

int main() {

	int t = 0, n = 0;
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d", &n);
		Node* root = NULL;
		int tmp;
		for (int i = 0; i<n; i++)
		{
			scanf_s("%d", &tmp);
			insertBST(&root, tmp);

		}
		int h = 0;
		int dai = diameter(root, &h);
		deleteNode(root);
		printf("%d", dai);


	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
