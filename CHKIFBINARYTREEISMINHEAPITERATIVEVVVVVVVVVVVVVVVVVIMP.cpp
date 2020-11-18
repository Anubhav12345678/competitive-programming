#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};

// Function to check if a given binary tree is a min heap or not
bool isHeap(Node* root)
{
	// create an empty queue and enqueue root node
	queue<Node*> queue;
	queue.push(root);

	// take a boolean flag which becomes true when an empty left
	// or right child is seen for a node
	bool nullseen = false;

	// run till queue is not empty
	while (queue.size())
	{
		// process front node in the queue
		Node* curr = queue.front();
		queue.pop();

		// left child is non-empty
		if (curr->left)
		{
			// if either heap-property is violated
			if (nullseen || curr->left->data <= curr->data)
				return false;

			// enqueue left child
			queue.push(curr->left);
		}
		// left child is empty
		else {
			nullseen = true;
		}

		// right child is non-empty
		if (curr->right)
		{
			// if either heap-property is violated
			if (nullseen || curr->right->data <= curr->data)
				return false;

			// enqueue left child
			queue.push(curr->right);
		}
		// right child is empty
		else {
			nullseen = true;
		}
	}

	// we reach here only when the given binary tree is a min-heap
	return true;
}

int main()
{
	/* Construct below binary tree
			   2
			 /   \
			/	 \
		   3	   4
		  / \	 / \
		 /   \   /   \
		5	 6 8	10
	*/

	Node* root = new Node(2);
	root->left = new Node(3);
	root->right = new Node(4);
	root->left->left = new Node(5);
	root->left->right = new Node(6);
	root->right->left = new Node(8);
	root->right->right = new Node(10);

	if (isHeap(root))
		cout << "Given Binary Tree is a min-Heap";
	else
		cout << "Given Binary Tree is not a min-Heap";

	return 0;
}