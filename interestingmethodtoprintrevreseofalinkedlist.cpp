// C program to print reverse of list 
#include <stdio.h> 
#include <stdlib.h> 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

/* Function to reverse the linked list */
void printReverse(struct Node** head_ref, int n) 
{ 
	int j = 0; 
	struct Node* current = *head_ref; 
	while (current != NULL) { 

		// For each node, print proper number 
		// of spaces before printing it 
		for (int i = 0; i < 2 * (n - j); i++) 
			printf(" "); 

		// use of carriage return to move back 
		// and print. 
		printf("%d\r", current->data); 

		current = current->next; 
		j++; 
	} 
} 

/* Function to push a node */
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = 
		(struct Node*)malloc(sizeof(struct Node)); 

	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Function to print linked list and find its 
length */
int printList(struct Node* head) 
{ 
	// i for finding length of list 
	int i = 0; 
	struct Node* temp = head; 
	while (temp != NULL) { 
		printf("%d ", temp->data); 
		temp = temp->next; 
		i++; 
	} 
	return i; 
} 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	// list nodes are as 6 5 4 3 2 1 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 4); 
	push(&head, 5); 
	push(&head, 6); 

	printf("Given linked list:n"); 
	// printlist print the list and 
	// return the size of list 
	int n = printList(head); 

	// print reverse list with help 
	// of carriage return function 
	printf("nReversed Linked list:n"); 
	printReverse(&head, n); 

	return 0; 
} 
