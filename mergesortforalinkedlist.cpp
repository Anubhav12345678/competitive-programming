#include <bits/stdc++.h>
using namespace std;
#define ll long long
//merge sort of a single link list
// typedef struct node* nptr
struct node
{
    int data;
    struct node* next;
};
struct node* SortedMerge(struct node* a, struct node* b) 
{ 
    struct node* result = NULL; 
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
}
void partition(struct node *head,struct node **a,struct node  **b)
{
  //a is front ref
	// b is back ref
	// head is a copy of the pointer to the head of the main link list
	struct node *fast,*slow;
	fast = head;
	slow = head;
	while(fast!=NULL)
	{
		fast = fast->next;
		if(fast!=NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}//now fast is null and slow pointer is at the mid or just after that
	*a = head;
	*b = slow->next;
	slow->next=NULL;
}
void Mergesort(struct node **headref)
{
	struct node* head = *headref;
	struct node *a;
	struct node *b;
	if(head==NULL||head->next==NULL)//if len of list ==1||0
		return;
	partition(head,&a,&b);

	Mergesort(&a);
	Mergesort(&b);

    *headref = SortedMerge(a,b);

}
void push(struct node **headref,int data)
{
    // struct node *head = *headref;
    struct node *nep = new node();
    nep->data = data;
    nep->next = *headref;
    *headref = nep;
}
void printList(struct node *head)
{
    if(head!=NULL)
    {
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
    }
}
int main() 
{ 
    /* Start with the empty list */
   struct node* res = NULL; 
   struct node* a = NULL; 
  
    /* Let us create a unsorted linked lists to test the functions  
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
  
    /* Sort the above created Linked List */
    Mergesort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    printList(a); 
  
    return 0; 
}