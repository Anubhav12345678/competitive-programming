#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
struct ListNode
{
	int val;
	struct ListNode* next; 
	ListNode(int x): val(x), next(NULL) {}
};
void push(struct ListNode** head,int n)
{
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->val = n;
	newnode->next = (*head);
	(*head) = newnode;
}
struct ListNode* removesumzero(struct ListNode* head)
{
	struct ListNode* st= new ListNode(0);
	st->next=head;
	int sum=0;
	while(1)
	{
		map<int,struct ListNode*> m;
		int sum=0;
		m[0]=st;
		struct ListNode* tmp = st->next;
		while(tmp)
		{
			sum+=tmp->val;
			if(m.find(sum)!=m.end())
			break;
			else
			m[sum]=tmp;
			tmp=tmp->next;
		}
		if(tmp)
		{
			tmp=tmp->next;
			struct ListNode* tmp2 = m[sum];
			while(tmp2->next!=tmp)
			tmp2->next=tmp2->next->next;
		}
		else
		break;
	}
	return st->next;
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	struct ListNode* head=NULL;
	for(int i=0;i<n;i++)
	push(&head,a[i]);
	struct ListNode* cpy = removesumzero(head);
	while(cpy)
	{
		cout<<cpy->val<<" ";
		cpy=cpy->next;
	}
	// your code goes here
	return 0;
}