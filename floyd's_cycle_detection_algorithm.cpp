//floyd's cycle detection algorithm
//detecting a loop
struct node
{
	int data;
	struct node *next;
};
int	 detect(struct node *head)
{
  struct node *p,*q;
  p=head;
  q = head;
  while(p && q && q->next)
  {
    p = p->next;
    q = (q->next)->next;
    if(p==q)
    	return p;
  }
  return NULL;

}
// returnns the starting of the loop for more details view https://www.youtube.com/watch?v=LUm2ABqAs1w
int find startoftheloop(struct node *p,struct node *head)//p returned from the previous function
{
	struct node *q;
	q = head;
	while(p!=q)
	{
		p=p->next;
		q = q->next;
	}
	return p;


}