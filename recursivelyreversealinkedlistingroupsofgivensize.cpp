/*Reverses the linked list in groups 
of size k and returns the pointer 
to the new head node. */
struct node *reverse (struct node *head, int k)
{ 
  int count = 0;
  struct node *prev,*next,*cur;
  cur = head;
  prev = NULL;
  next = NULL;
  while(count<k&&cur!=NULL)
  {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      count++;
  }
  
  if(next!=NULL)
  head->next = reverse(next,k);
  
  return prev;
}