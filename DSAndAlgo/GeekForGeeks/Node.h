
/* A binary tree Node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
 

/* Helper function that allocates a new Node with the
   given data and NULL left and right pointers. */
 Node* newNode(int data)
{
    Node* n = new Node();
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
 
    return(n);
}

void deleteTree(Node* root)
{
	if(root == nullptr)
		return;
	if(root->left)
		deleteTree(root->left);
	if(root->right)
		deleteTree(root->right);
	delete root;
	root =nullptr;
}