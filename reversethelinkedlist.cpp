Node* reverseList(Node *head)
{
    Node *cur,*next,*prev,*k;
    cur=head;
    next = NULL;
    prev=NULL;
    while(cur!=NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev=cur;
        cur=next;
    }
    head = prev;
    return head;
    
  // Your code here
}