#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <utility>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = nullptr;

	return node;
}

// Helper function to print a doubly linked list
void printDoublyList(Node* ptr)
{
	while (ptr)
	{
		cout << ptr->key << " -> ";
		ptr = ptr->right;
	}
	cout << "nullptr";
}

// Insert a tree node at the front of the doubly linked list
void push(Node* node, Node* &headRef)
{
	// initialize head pointer of doubly linked list
	if (headRef == nullptr) {
		headRef = node;
		headRef->left = headRef->right = nullptr;
		return;
	}

	// insert given node at the front of the doubly linked list
	headRef->left = node;
	node->right = headRef;

	// update left child pointer to null
	node->left = nullptr;

	// update head pointer to point to given node
	headRef = node;
}

// Traverse the tree in preorder fashion and store nodes into the map
// corresponding to their level
void preorder(Node *root, int level, auto &map)
{
	// base case: empty tree
	if (root == nullptr)
		return;

	// insert current node and its level into the map

	// if level is odd insert at front, else insert at back
	if (level & 1)
		map[level].push_front(root);
	else
		map[level].push_back(root);

	// recur for left and right subtree with level increased by 1
	preorder(root->left, level + 1, map);
	preorder(root->right, level + 1, map);
}

// Recursive function to convert a binary tree into a doubly linked list
// using Hashing
void convert(Node *root, Node* &headRef)
{
	// create an empty map to store nodes between given levels
	unordered_map<int, list<Node*>> map;

	// traverse the tree and insert its nodes into the map
	// corresponding to the their level
	preorder(root, 0, map);

	// iterate through the map in decreasing order of level and
	// push nodes of each level into the doubly linked list
	int n = map.size();
	for (int i = n - 1; i >=0; i--)
	{
		for (Node* node: map[i]) {
			push(node, headRef);
		}
	}
}

// main function
int main()
{
	Node* root = nullptr;

	/* Construct below tree
              1
            /   \
           /     \
          2       3
         / \     / \
        /   \   /   \
       4     5 6     7
	*/

	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	Node* head = nullptr;
	convert(root, head);
	printDoublyList(head);

	return 0;
}