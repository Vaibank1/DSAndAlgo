
#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>


struct Node{
	int data;
	Node *left,*right;
	Node(int a)
	{
		data = a;
		left = NULL;
		right = NULL;
	}
	Node()
	{
		left = NULL;
		right = NULL;
	}
};

void recurse(Node* root, Node** cur, bool& isFirst, Node** head_ref)
{
    
    if(root == NULL)
    return;
	recurse(root->left, cur,isFirst,head_ref);
    if(root->right == NULL && root->left == NULL)
    {
        
         if(!isFirst)
        {
            //crete first node
            
            *head_ref = new Node();
			(*head_ref)->data= root->data;
            (*head_ref )->left = NULL;
            (*head_ref )->right = NULL;
            
            *cur= *head_ref;
            isFirst = true;
            
            
        }
        else 
        {
            //head is already created
            
			Node* newNode = new Node();    
			newNode->data= root->data;
            newNode->left = (*cur);
            (*cur)->right = newNode;
            (*cur) = newNode;
            }
        
    }   
    recurse(root->right,cur,isFirst,head_ref);
    
}

Node *convertToDLL(Node *root,Node **head_ref)
{

    if(root == NULL)
    return root;
    if(root->right == NULL && root->left == NULL)
    {
        Node* newNode = new Node();    
		newNode->data= root->data;             
        newNode->left = NULL;
        newNode->right = NULL;
       (*head_ref) = newNode;
	   return root;        
    
    }
	bool isFirst = false;
	Node* cur=NULL;
    recurse(root,&cur ,isFirst,head_ref);
    
    return root;   
    
}

bool isIsomorphic(Node *n1,Node *n2)
{
 // Both roots are NULL, trees isomorphic by definition
 if (n1 == NULL && n2 == NULL)
    return true;
 
 // Exactly one of the n1 and n2 is NULL, trees not isomorphic
 if (n1 == NULL || n2 == NULL)
    return false;
 
 if (n1->data != n2->data)
    return false;
 
 // There are two possible cases for n1 and n2 to be isomorphic
 // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
 // Both of these subtrees have to be isomorphic, hence the &&
 // Case 2: The subtrees rooted at these nodes have been "Flipped"
 return
 (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right))||
 (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left));
    


}
void printDLL(Node* root)
{
	while(root)
	{
		std::cout<<root->data<<"\t";
		root = root->right;
	}
}
int main() {

    Node *root = new  Node(1);
  root->left        = new  Node(2);
  root->right       = new  Node(3);
  root->left->left  = new  Node(4);
  root->left->right = new  Node(5);
  Node *head_ref = NULL;
  convertToDLL(root,&head_ref);
  printDLL(head_ref);
  bool ans = isIsomorphic(root,root);
    return 0;
}