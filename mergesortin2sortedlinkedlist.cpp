#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* SortedMerge(struct node* p,struct node* q)
{
    // struct node* sort,*newnode;
    if(p==NULL)
        return q;
    if(q==NULL)
        return p;
         struct node* sort,*newnode;
    if(p&&q)
    {
        if(p->data<=q->data)
        {
            sort = p;
            p = p->next;
        }
        else
        {
            sort = q;
            q = q->next;
        }
    }
    newnode = sort;
    while(p&&q)
    {
        if(p->data<=q->data)
        {
            sort->next = p;
            sort = p;
            p = p->next;
        }
        else
        {
            sort->next = q;
            sort = q;
            q = q->next;
        }
    }
    if(p==NULL)
        sort->next=q;
    else if(q==NULL)
        sort->next = p;
    return newnode;

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
    node* res = NULL;  
    node* a = NULL;  
    node* b = NULL;  
  
    /* Let us create two sorted linked lists   
    to test the functions  
    Created lists, a: 5->10->15, b: 2->3->20 */
    push(&a, 15);  
    push(&a, 10);  
    push(&a, 5);  
  
    push(&b, 20);  
    push(&b, 3);  
    push(&b, 2);  
  
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);  
  
    cout << "Merged Linked List is: \n";  
    printList(res);  
  
    return 0;  
} 