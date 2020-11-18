#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node {
	int x, y;
	struct Node* next;
};

// Helper function to insert new node in the beginning of the linked list
void push(struct Node** headRef, int x, int y)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->x = x;
	node->y = y;
	node->next = *headRef;

	*headRef = node;
}

// Function to remove redundant nodes from a path formed by a linked list
void removeNodes(struct Node **head)
{
	struct Node* curr = *head;

	while (curr->next && curr->next->next)
	{
		struct Node *temp = curr->next->next;

		// check for a vertical triplet (triplet with same x-value)
		if (curr->x == curr->next->x && curr->x == temp->x)
		{
			// delete middle node
			free(curr->next);
			curr->next = temp;
		}

		// check for a horizontal triplet (triplet with same y-value)
		else if (curr->y == curr->next->y && curr->y == temp->y)
		{
			// delete middle node
			free(curr->next);
			curr->next = temp;
		}
		else
		{
			curr=curr->next;
		}
	}
}

// Helper function to print given linked list
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("(%d, %d) -> ", ptr->x, ptr->y);
		ptr = ptr->next;
	}

	printf("null\n");
}

// main method
int main(void)
{
	// input coordinates
	int keys[][2] = { {0, 1}, {0, 5}, {0, 8}, {2, 8},
					  {5, 8}, {7, 8}, {7, 10}, {7, 12} };

	int n = sizeof(keys) / sizeof(keys[0]);

	struct Node* head = NULL;
	for (int i = n - 1; i >= 0; i--)
		push(&head, keys[i][0], keys[i][1]);

	removeNodes(&head);
	printList(head);

	return 0;
}