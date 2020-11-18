#include<bits/stdc++.h>
using namespace std;
#define ll long long
class node  
{  
    public: 
    int data;  
    node* next;  
};
ll getintersection(ll d,node* head1,node* head2)
{
  ll i;
  node* cur1 = head1;
  node* cur2 = head2;
   if(!cur1||!cur2)
   	return -1;
  for(i=0;i<d;i++)
  {
  	if(cur1==NULL)
  		return -1;
  	cur1 = cur1->next;
  	// if(cur1==NULL)
  	// 	return -1;

  }
  while(cur1!=NULL||cur2!=NULL)
  {
  	if(!cur1||!cur2)
  		return -1;
  	if(cur1==cur2)
  		return cur2->data;
  	cur1 = cur1->next;
  	cur2 = cur2->next;
  }
}
ll _getintersect(node* head1,node* head2)
{
   node* cur1 = head1;
   node* cur2 = head2;
   ll c1=0,c2=0;
   while(cur1!=NULL)
   {
   	c1++;
   	cur1 = cur1->next;
   }
   while(cur2!=NULL)
   {
   	c2++;
   	cur2 = cur2->next;
   }
   if(c1>c2)
   	return getintersection((c1-c2),head1,head2);
   else
   	return getintersection((c2-c1),head2,head1);
}
int main()  
{  
    /*  
        Create two linked lists  
      
        1st 3->6->9->15->30  
        2nd 10->15->30  
      
        15 is the intersection point  
    */
      
    node* newNode;  
    node* head1 =new node();  
    head1->data = 10;  
      
    node* head2 =new node();  
    head2->data = 3;  
      
    newNode = new node();  
    newNode->data = 6;  
    head2->next = newNode;  
      
    newNode = new node();  
    newNode->data = 9;  
    head2->next->next = newNode;  
      
    newNode = new node();  
    newNode->data = 15;  
    head1->next = newNode;  
    head2->next->next->next = newNode;  
      
    newNode = new node();  
    newNode->data = 30;  
    head1->next->next= newNode;  
      
    head1->next->next->next = NULL;  
      
    cout<<"The node of intersection is "<<_getintersect(head1, head2);  
}  
