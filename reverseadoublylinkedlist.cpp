void reverse(struct node **head_ref)
{
    if(!(*head_ref)||!((*head_ref)->next))
    return;
    struct node *cpy = *head_ref;
    struct node *t = *head_ref;
    struct node *tmp  = NULL;
    tmp = cpy->next;
    struct node* previous = NULL;
    while(tmp!=NULL)
    {
        cpy->next = previous;
        cpy->prev = tmp;
        previous = cpy;
        cpy = tmp;
        tmp = tmp->next;
    }
    cpy->next = previous;
    cpy->prev = tmp;
    previous = cpy;
    cpy = tmp;
    (*head_ref) = previous;
    
   // Your code goes here
}