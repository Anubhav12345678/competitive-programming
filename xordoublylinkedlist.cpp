#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <inttypes.h> 
class node
{
	public:
	ll data;
	node* npx;
};
node* XOR (node* a, node* b)
{
	return  (node*)( (uintptr_t)(a) ^ (uintptr_t)(b)); 
}
void insert (node** head,ll data)
{
    node* newnode = new node();
	newnode->data = data;
	newnode->npx = XOR(*head,NULL);
	if(*head!=NULL)
	{
		// newnode->npx = XOR(*head->npx,NULL);
	 node* next = XOR((*head)->npx,NULL);
		(*head)->npx = XOR(newnode,next);
	}
	(*head) = newnode;
	
}

void printList  (node *head)  
{  
    node *curr = head;  
    node *prev = NULL;  
    node *next;  
  
    cout << "Following are the nodes of Linked List: \n";  
  
    while (curr != NULL)  
    {  
        // print current node  
        cout<<curr->data<<" ";  
  
        // get address of next node: curr->npx is  
        // next^prev, so curr->npx^prev will be  
        // next^prev^prev which is next  
        next = XOR (prev, curr->npx);  
  
        // update prev and curr for next iteration  
        prev = curr;  
        curr = next;  
    }  
}  
  
// Driver code  
int main ()  
{  
    /* Create following Doubly Linked List  
    head-->40<-->30<-->20<-->10 */
    node *head = NULL;  
    insert(&head, 10);  
    insert(&head, 20);  
    insert(&head, 30);  
    insert(&head, 40);  
  
    // print the created list  
    printList (head);  
  
    return (0);  
} 