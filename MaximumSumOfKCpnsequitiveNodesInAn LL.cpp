// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Structure of a node 
struct Node { 
	int data; 
	Node* next; 
}; 

// Function to create new node 
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->next = NULL; 
	node->data = data; 
	return node; 
} 

// Function to return the maximum sum of 
// k consecutive nodes 
int findMaxSum(Node* head, int k) 
{ 
	// To store current window sum 
	int sum = 0; 

	// To store maximum sum 
	int maxSum = 0; 

	// Pointer to the start of window 
	Node* start = head; 

	// Pointer to the end of window 
	Node* end = head; 

	int i; 

	// Find the sum of first k nodes 
	for (i = 0; i < k; i++) { 
		sum += end->data; 
		end = end->next; 
	} 

	maxSum = sum; 

	// Move window by one step and 
	// update sum. Node pointed by 
	// start is excluded from current 
	// window so subtract it. Node 
	// pointed by end is added to 
	// current window so add its value. 
	while (end != NULL) { 

		// Subtract the starting element 
		// from previous window 
		sum -= start->data; 
		start = start->next; 

		// Add the element next to the end 
		// of previous window 
		sum += end->data; 
		end = end->next; 

		// Update the maximum sum so far 
		maxSum = max(maxSum, sum); 
	} 

	return maxSum; 
} 

// Driver code 
int main() 
{ 
	Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(5); 
	head->next->next->next->next->next = newNode(6); 

	int k = 5; 

	cout << findMaxSum(head, k); 

	return 0; 
} 
