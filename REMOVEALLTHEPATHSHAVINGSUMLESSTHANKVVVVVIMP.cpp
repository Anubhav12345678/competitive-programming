// a simpler solution
#include <bits/stdc++.h> 
using namespace std; 

// A Binary Tree Node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new Binary 
// Tree node with given data 
struct Node* newNode(int data) 
{ 
	struct Node* node = 
	(struct Node*) malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

// print the tree in LVR (Inorder traversal) way. 
void print(struct Node *root) 
{ 
	if (root != NULL) 
	{ 
		print(root->left); 
		cout << root->data << " "; 
		print(root->right); 
	} 
} 

/* Main function which truncates the binary tree. */
struct Node *prune(struct Node *root, int sum) 
{ 
	// Base Case 
	if (root == NULL) return NULL; 

	// Recur for left and right subtrees 
	root->left = prune(root->left, sum - root->data); 
	root->right = prune(root->right, sum - root->data); 

	// If we reach leaf whose data is smaller than sum, 
	// we delete the leaf. An important thing to note 
	// is a non-leaf node can become leaf when its 
	// chilren are deleted. 
	if (root->left==NULL && root->right==NULL) 
	{ 
		if (root->data < sum) 
		{ 
			free(root); 
			return NULL; 
		} 
	} 

	return root; 
} 

// Driver program to test above function 
int main() 
{ 
	int k = 45; 
	struct Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->left->left->left = newNode(8); 
	root->left->left->right = newNode(9); 
	root->left->right->left = newNode(12); 
	root->right->right->left = newNode(10); 
	root->right->right->left->right = newNode(11); 
	root->left->left->right->left = newNode(13); 
	root->left->left->right->right = newNode(14); 
	root->left->left->right->right->left = newNode(15); 

	cout << "Tree before truncation\n"; 
	print(root); 

	root = prune(root, k); // k is 45 

	cout << "\n\nTree after truncation\n"; 
	print(root); 

	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 


#include <stdio.h> 
#include <stdlib.h> 

// A utility function to get maximum of two integers 
int max(int l, int r) { return (l > r ? l : r); } 

// A Binary Tree Node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new Binary Tree node with given data 
struct Node* newNode(int data) 
{ 
	struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

// print the tree in LVR (Inorder traversal) way. 
void print(struct Node *root) 
{ 
	if (root != NULL) 
	{ 
		print(root->left); 
		printf("%d ",root->data); 
		print(root->right); 
	} 
} 

/* Main function which truncates the binary tree. */
struct Node *pruneUtil(struct Node *root, int k, int *sum) 
{ 
	// Base Case 
	if (root == NULL) return NULL; 

	// Initialize left and right sums as sum from root to 
	// this node (including this node) 
	int lsum = *sum + (root->data); 
	int rsum = lsum; 

	// Recursively prune left and right subtrees 
	root->left = pruneUtil(root->left, k, &lsum); 
	root->right = pruneUtil(root->right, k, &rsum); 

	// Get the maximum of left and right sums 
	*sum = max(lsum, rsum); 

	// If maximum is smaller than k, then this node 
	// must be deleted 
	if (*sum < k) 
	{ 
		free(root); 
		root = NULL; 
	} 

	return root; 
} 

// A wrapper over pruneUtil() 
struct Node *prune(struct Node *root, int k) 
{ 
	int sum = 0; 
	return pruneUtil(root, k, &sum); 
} 

// Driver program to test above function 
int main() 
{ 
	int k = 45; 
	struct Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->left->left->left = newNode(8); 
	root->left->left->right = newNode(9); 
	root->left->right->left = newNode(12); 
	root->right->right->left = newNode(10); 
	root->right->right->left->right = newNode(11); 
	root->left->left->right->left = newNode(13); 
	root->left->left->right->right = newNode(14); 
	root->left->left->right->right->left = newNode(15); 

	printf("Tree before truncation\n"); 
	print(root); 

	root = prune(root, k); // k is 45 

	printf("\n\nTree after truncation\n"); 
	print(root); 

	return 0; 
} 
