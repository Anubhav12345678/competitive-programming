//remove loop- for this we need to detect the loop first
struct node
{
	int data;
	struct node *next;
};
void remove(struct Node *loop_node, struct Node *head)
{
	struct Node *ptr1; 
   struct Node *ptr2;
   ptr1 =head;
   while(1)
   {
   	ptr2 = loop_node;
   	while(ptr2->next != loop_node && ptr2->next != ptr1)
   		ptr2 = ptr2->next;
   	if (ptr2->next == ptr1) 
        break;
    /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
     ptr1 = ptr1->next; 
   }
   /* After the end of loop ptr2 is the last node of the loop. So 
     make next of ptr2 as NULL */
   ptr2->next = NULL;
}