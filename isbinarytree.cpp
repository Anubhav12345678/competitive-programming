// C++ program to check if a given tree is BST. 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to 
left child and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// Returns true if given tree is BST. 
bool isBST(Node* root, Node* l=NULL, Node* r=NULL) 
{ 
	// Base condition 
	if (root == NULL) 
		return true; 

	// if left node exist then check it has 
	// correct data or not i.e. left node's data 
	// should be less than root's data 
	if (l != NULL and root->data < l->data) 
		return false; 

	// if right node exist then check it has 
	// correct data or not i.e. right node's data 
	// should be greater than root's data 
	if (r != NULL and root->data > r->data) 
		return false; 

	// check recursively for every node. 
	return isBST(root->left, l, root) and 
		isBST(root->right, root, r); 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	struct Node *root = newNode(3); 
	root->left	 = newNode(2); 
	root->right	 = newNode(5); 
	root->left->left = newNode(1); 
	root->left->right = newNode(4); 

	if (isBST(root,NULL,NULL)) 
		cout << "Is BST"; 
	else
		cout << "Not a BST"; 

	return 0; 
} 

//another method
bool isBST(struct node* root) 
{ 
	static struct node *prev = NULL; 
	
	// traverse the tree in inorder fashion and keep track of prev node 
	if (root) 
	{ 
		if (!isBST(root->left)) 
		return false; 

		// Allows only distinct valued nodes 
		if (prev != NULL && root->data <= prev->data) 
		return false; 

		prev = root; 

		return isBST(root->right); 
	} 

	return true; 
} 
//
//another method



// C++ program to check if a given tree is BST. 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to 
left child and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 


bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
	// traverse the tree in inorder fashion and 
	// keep track of prev node 
	if (root) 
	{ 
		if (!isBSTUtil(root->left, prev)) 
		return false; 

		// Allows only distinct valued nodes 
		if (prev != NULL && root->data <= prev->data) 
		return false; 

		prev = root; 

		return isBSTUtil(root->right, prev); 
	} 

	return true; 
} 

bool isBST(Node *root) 
{ 
Node *prev = NULL; 
return isBSTUtil(root, prev); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	struct Node *root = new Node(3); 
	root->left	 = new Node(2); 
	root->right	 = new Node(5); 
	root->left->left = new Node(1); 
	root->left->right = new Node(4); 

	if (isBST(root)) 
		cout << "Is BST"; 
	else
		cout << "Not a BST"; 

	return 0; 
} 

