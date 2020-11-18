#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// Data structure to store a Binary Tree node
struct Node {
	int data;
	Node* left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

// Recursive function to perform inorder traversal of a binary tree
void inorderTraversal(Node* root)
{
	if (root == nullptr)
		return;

	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

// Recursive function to construct a binary tree from in-order and
// level-order traversals
Node* buildTree(int inorder[], int start, int end,
				unordered_map<int, int> map)
{
	// base case
	if (start > end)
		return nullptr;

	// find the index of root node in inorder[] to determine the
	// boundary of left and right subtree
	int index = start;
	for (int j = start + 1; j <= end; j++)
	{
		// find node with minimum index in level-order traversal
		// That would be the root node of inorder[start, end]
		if (map[inorder[j]] < map[inorder[index]])
			index = j;
	}

	// construct the root node
	Node* root = newNode(inorder[index]);

	// recursively construct the left subtree
	root->left = buildTree(inorder, start, index - 1, map);

	// recursively construct the right subtree
	root->right = buildTree(inorder, index + 1, end, map);

	// return root node
	return root;
}

// Construct a binary tree from in-order and level-order traversals
Node* buildTree(int in[], int level[], int n)
{
	// create a map to efficiently find index of an element in
	// level-order sequence
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++)
		map[level[i]] = i;

	// Construct the tree and return it
	return buildTree(in, 0, n - 1, map);
}

// main function
int main()
{
	int inorder[] = { 4, 2, 5, 1, 6, 3, 7 };
	int level[]   = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(inorder)/sizeof(inorder[0]);

	Node* root = buildTree(inorder, level, n);

	cout << "Inorder traversal of the constructed tree: ";
	inorderTraversal(root);

	return 0;
}