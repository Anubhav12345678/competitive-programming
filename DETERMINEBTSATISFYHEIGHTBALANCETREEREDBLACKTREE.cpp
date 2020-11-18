#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

// Recursive function to determine if the given binary tree
// satisfy the height-balanced property of red–black tree or not
// It takes reference to rootMax variable for storing the
// maximum height of the root node
bool isHeightBalanced(Node *root, int &rootMax)
{
	// Base case
	if (root == nullptr)
		return true;

	// variables to hold maximum height of left and right subtree
	int leftMax = 0, rightMax = 0;

	// proceed only if both left and right subtree are balanced
	if (isHeightBalanced(root->left, leftMax) &&
		isHeightBalanced(root->right, rightMax))
	{
		// Calculate the minimum and maximum height of the left and right subtree
		int rootMin = min(leftMax, rightMax) + 1;
		rootMax = max(leftMax, rightMax) + 1;

		// return true if the root node is height balanced
		return (rootMax <= 2*rootMin);
	}

	// return false if either left or right subtree is unbalanced
	return false;
}

// main function
int main()
{
	/* Construct below tree
               1
             /   \
            /     \
           2       3
          /       / \
         /       /   \
        4       5     6
               / \
              /   \
             7     8
            / \
           /   \
          9    10
	*/

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->left = newNode(7);
	root->right->left->right = newNode(8);
	root->right->left->left->left = newNode(9);
	root->right->left->left->right = newNode(10);

	int rootMax = 0;

	if (isHeightBalanced(root, rootMax))
		cout << "Given Binary tree is height-balanced";
	else
		cout << "Given Binary tree is not height-balanced";

	return 0;
}