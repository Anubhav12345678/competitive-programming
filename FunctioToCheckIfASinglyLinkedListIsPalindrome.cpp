//https://ideone.com/OF460r
//RECURSIVE METHOD VVVIMP
#include <iostream>
using namespace std;

// Data Structure to store a linked list node
struct Node {
	char data;
	Node* next;

	Node(char ch)
	{
		this->data = ch;
		this->next = nullptr;
	}
};

// Recursive function to check if a given linked list of characters is
// palindrome. Note that the left pointer is passed by reference and
// the right pointer is just a copy
bool isPalindrome(Node*& left, Node* right)
{
	// base case
	if (right == nullptr)
		return true;

	// return false on first mismatch
	if (!isPalindrome(left, right->next))
		return false;

	// copy left pointer
	Node* prevLeft = left;
	
	// advance the left pointer to the next node
	// this change would reflect in the parent recursive calls
	left = left->next;

	// In order for linked list to be palindrome, the character at the left
	// node should match with the character at the right node
	return (prevLeft->data == right->data);
}

// main function
int main()
{
	Node* head = new Node('A');
	head->next = new Node('B');
	head->next->next = new Node('C');
	head->next->next->next = new Node('B');
	head->next->next->next->next = new Node('A');

	if (isPalindrome(head, head))
		cout << "Linked List is a palindrome.";
	else
		cout << "Linked List is not a palindrome.";

	return 0;
}






#include<bits/stdc++.h> 
using namespace std; 

class Node { 
public: 
		int data; 
		Node(int d){ 
			data = d; 
		} 
		Node *ptr; 
}; 

// Function to check if the linked list 
// is palindrome or not 
bool isPalin(Node* head){ 
		
		// Temp pointer 
		Node* slow= head; 

		// Declare a stack 
		stack <int> s; 


		// Push all elements of the list 
		// to the stack 
		while(slow != NULL){ 
				s.push(slow->data); 

				// Move ahead 
				slow = slow->ptr; 
		} 

		// Iterate in the list again and 
		// check by popping from the stack 
		while(head != NULL ){ 
			
			// Get the top most element 
			int i=s.top(); 

			// Pop the element 
			s.pop(); 

			// Check if data is not 
			// same as popped element 
			if(head -> data != i){ 
				return false; 
			} 

			// Move ahead 
		head=head->ptr; 
		} 

return true; 
} 

// Driver Code 
int main(){ 

	// Addition of linked list 
	Node one = Node(1); 
	Node two = Node(2); 
	Node three = Node(3); 
	Node four = Node(2); 
	Node five = Node(1); 

	// Initialize the next pointer 
	// of every current pointer 
	five.ptr = NULL; 
	one.ptr = &two; 
	two.ptr = &three; 
	three.ptr = &four; 
	four.ptr = &five; 
	Node* temp = &one; 

	
	// Call function to check palindrome or not 
	int result = isPalin(&one); 
	
	if(result == 1) 
			cout<<"isPalindrome is true\n"; 
	else
		cout<<"isPalindrome is true\n"; 

return 0; 
} 

// This code has been contributed by Striver 
