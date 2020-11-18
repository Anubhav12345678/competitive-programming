// CPP program to move all zeros 
// to the end of the linked list. 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
struct Node { 
int data; 
struct Node *next; 
}; 

/* Given a reference (pointer to pointer) to 
the head of a list and an int, push a new 
node on the front of the list. */
void push(struct Node **head_ref, int new_data) { 
struct Node *new_node = new Node; 
new_node->data = new_data; 
new_node->next = (*head_ref); 
(*head_ref) = new_node; 
} 

/* moving zeroes to the begining in linked list */
void moveZeroes(struct Node **head) { 
if (*head == NULL) 
	return; 

// Traverse the list from second node. 
struct Node *temp = (*head)->next, *prev = *head; 
while (temp != NULL) { 

	// If current node is 0, move to 
	// beginning of linked list 
	if (temp->data == 0) { 

	// Disconnect node from its 
	// current position 
	Node *curr = temp; 
	temp = temp->next; 
	prev->next = temp; 

	// Move to beginning 
	curr->next = (*head); 
	*head = curr; 
	} 

	// For non-zero values 
	else { 
	prev = temp; 
	temp = temp->next; 
	} 
} 
} 

// function to displaying nodes 
void display(struct Node *head) { 
while (head != NULL) { 
	cout << head->data << "->"; 
	head = head->next; 
} 
cout << "NULL"; 
} 

/* Drier program to test above function*/
int main() { 

/* Start with the empty list */
struct Node *head = NULL; 

/* Use push() to construct below list 
0->0->1->0->1->0->2->0->3->0 */
push(&head, 0); 
push(&head, 3); 
push(&head, 0); 
push(&head, 2); 
push(&head, 0); 
push(&head, 1); 
push(&head, 0); 
push(&head, 1); 
push(&head, 0); 
push(&head, 0); 

// displaying list before rearrangement 
cout << "Linked list before rearrangement\n"; 
display(head); 

/* Check the move_zeroes function */
moveZeroes(&head); 

// displaying list after rearrangement 
cout << "\n Linked list after rearrangement \n"; 
display(head); 

return 0; 
} 
