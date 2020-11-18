#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next, *random;

	// Constructor
	Node(int data)
	{
		this->data = data;
		this->next = this->random = nullptr;
	}
};

// Helper function to insert new Node in the beginning of the linked list
void push(Node* &head, int data)
{
	Node* newNode = new Node(data);
	newNode->next = head;
	head = newNode;
}

// Function to print a linked list with extra random pointer
void printList(string msg, Node* head)
{
	cout << msg;
	while (head)
	{
		cout << head->data;

		if (head->random)
			cout << "(" << head->random->data << ") -> ";
		else
			cout << "(X) -> ";

		head = head->next;
	}

	cout << "X" << '\n';
}

// Function to reverse a linked list by changing its .next pointers
// and its head pointer. It takes a reference to the head pointer.
void reverse(Node* &head)
{
	Node* prev = nullptr;	// the prev pointer
	Node* curr = head;		// the main pointer

	// traverse the list
	while (curr)
	{
		// tricky: note the next node
		Node* next = curr->next;

		curr->next = prev;  // fix the curr node

		// advance the two pointers
		prev = curr;
		curr = next;
	}

	// fix the head pointer to point to the new front
	head = prev;
}

// Function to update random pointer of each linked list node
// to point to node with maximum value to their right
void setRandomNodes(Node* &head)
{
	// Reverse the linked list
	reverse(head);

	// max points to the node with maximum value
	Node* max = head;
	head->random = nullptr;

	// start from the second node in the list
	Node* node = head->next;
	while (node)
	{
		// update random pointer of current node to point to the
		// maximum value node so far
		node->random = max;

		// update max if current node is greater
		if (max->data < node->data)
			max = node;

		// advance to the next node
		node = node->next;
	}

	// restore the linked list original order
	reverse(head);
}

// main function
int main()
{
	// input keys
	vector<int> keys = { 5, 10, 7, 9, 4, 3 };
	Node* head = nullptr;
	for (int i = keys.size() - 1; i >= 0; i--)
		push(head, keys[i]);

	printList("Original Linked List: ", head);

	// assign random nodes
	setRandomNodes(head);

	printList("  Final Linked List: ", head);

	return 0;
}