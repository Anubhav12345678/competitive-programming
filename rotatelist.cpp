void rotate(struct node **head_ref, int k)
{
   struct node *cur = *head_ref;
   struct node *copy,*prev,*prev2;
//   cur = head;
   copy = cur;
   int n=1;
   while(n<k && cur!=NULL)
   {
       cur = cur->next;
       n++;
   }
struct node *kth;
  kth = cur;
   k = k%n;
   while(cur->next!=NULL)
   cur=cur->next;
//   cur = copy;
   cur->next = head;
   head = kth->next;
   kth->next = NULL;
   
}