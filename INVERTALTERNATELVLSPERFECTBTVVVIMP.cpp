#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
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

// Function to print level order traversal of a perfect binary tree
void levelOrderTraversal(Node* root)
{
	if (root == nullptr)
		return;

	// create an empty queue and enqueue root node
	queue<Node*> queue;
	queue.push(root);

	// pointer to store current node
	Node* curr = nullptr;

	// run till queue is not empty
	while (queue.size())
	{
		// process each node in queue and enqueue their
		// non-empty left and right child to queue
		curr = queue.front();
		queue.pop();

		cout << curr->data << " ";

		if (curr->left)
			queue.push(curr->left);

		if (curr->right)
			queue.push(curr->right);
	}
}

// Iterative function to invert alternate levels of a perfect binary tree
// using level order traversal
void invertBinaryTree(Node* root)
{
	// base case: if tree is empty
	if (root == nullptr)
		return;
 
	// maintain a queue and enqueue root node
	queue<Node*> q;
	q.push(root);
 
	// to store current level information
	bool level = false;
	
	// queue to store nodes present in an odd level
	queue<Node*> level_nodes;

	// stack to store node's data in an odd level
	stack<int> level_data;
 
	// run till queue is not empty
	while (!q.empty())
	{
		// get size of current level
		int n = q.size();
 
		// process all nodes present in current level
		while (n--)
		{
			// remove front node from queue
			Node* curr = q.front();
			q.pop();
 
			// if level is odd
			if (level)
			{
				// push current node into the queue
				level_nodes.push(curr);
 
				// push data of current node into the stack
				level_data.push(curr->data);
			}
 
			// if current node is last node of the level
			if (n == 0)
			{
				// flip the level
				level = !level;
 
				// put elements present in the level_data into their correct
				// position using level_nodes
				while (!level_nodes.empty())
				{
					Node* front = level_nodes.front();
					front->data = level_data.top();
 
					level_nodes.pop();
					level_data.pop();
				}
			}
 
			// push left child of current node to the queue
			if (curr->left)
				q.push(curr->left);
 
			// push right child of current node to the queue
			if (curr->right)
				q.push(curr->right);
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
            /       \
          2           3
        /   \       /   \
       4     5     6     7
      / \   / \   / \   / \
     8   9 10 11 12 13 14 15
	*/

	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(11);
	root->right->left->left = newNode(12);
	root->right->left->right = newNode(13);
	root->right->right->left = newNode(14);
	root->right->right->right = newNode(15);

	invertBinaryTree(root);
	levelOrderTraversal(root);

	return 0;
}