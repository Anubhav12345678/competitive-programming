// C++ implementation to count pairs in a binary tree 
// whose sum is equal to given value x 
#include <bits/stdc++.h> 
using namespace std; 

// structure of a node of a binary tree 
struct Node { 
	int data; 
	Node *left, *right; 
}; 

// function to create and return a node 
// of a binary tree 
Node* getNode(int data) 
{ 
	// allocate space for the node 
	Node* new_node = (Node*)malloc(sizeof(Node)); 

	// put in the data 
	new_node->data = data; 
	new_node->left = new_node->right = NULL; 
} 

// returns true if a pair exists with given sum 'x' 
bool findPair(Node* root, Node* temp, int x) 
{ 
	// base case 
	if (!root) 
		return false; 

	// pair exists 
	if (root != temp && ((root->data + temp->data) == x)) 
		return true; 

	// find pair in left and right subtress 
	if (findPair(root->left, temp, x) || findPair(root->right, temp, x)) 
		return true; 

	// pair does not exists with given sum 'x' 
	return false; 
} 

// function to count pairs in a binary tree 
// whose sum is equal to given value x 
void countPairs(Node* root, Node* curr, int x, int& count) 
{ 
	// if tree is empty 
	if (!curr) 
		return; 

	// check whether pair exists for current node 'curr' 
	// in the binary tree that sum up to 'x' 
	if (findPair(root, curr, x)) 
		count++; 

	// recursively count pairs in left subtree 
	countPairs(root, curr->left, x, count); 

	// recursively count pairs in right subtree 
	countPairs(root, curr->right, x, count); 
} 

// Driver program to test above 
int main() 
{ 
	// formation of binary tree 
	Node* root = getNode(5); /*	 5	 */
	root->left = getNode(3); /*	 / \	 */
	root->right = getNode(7); /* 3 7	 */
	root->left->left = getNode(2); /* / \ / \ */
	root->left->right = getNode(4); /* 2 4 6 8 */
	root->right->left = getNode(6); 
	root->right->right = getNode(8); 

	int x = 10; 
	int count = 0; 

	countPairs(root, root, x, count); 
	count = count / 2; 

	cout << "Count = " << count; 

	return 0; 
} 
