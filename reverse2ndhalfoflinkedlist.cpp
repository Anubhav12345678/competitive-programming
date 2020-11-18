#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<stdlib.h>
struct node
{
	ll data;
	struct node* next;
};
void insert(struct node** root,ll data)
{
	struct node* t = (struct node*)malloc(sizeof(struct node));
	t->data = data;
	t->next = NULL;
    if((*root)==NULL)
    {
    	(*root)= t;
    }
    else
    {
    	struct node* temp = *root;
    	while(temp->next)
    	temp = temp->next;
    	temp->next = t;
    }
}
void showdata(struct node* root)
{
	if(root ==NULL)
	cout<<"Empty list\n";
	else
	{
		while(root)
		{
			cout<<root->data<<" ";
			root = root->next;
		}
	}
}
void reversehalf(struct node** root)
{
	if((*root)==NULL)
	return;
	else if((*root)->next!=NULL)
	{
		struct node* temp = (*root);
		struct node* helper = NULL;
		struct node* store = NULL;
		 struct node* auxiliary = (*root);
		while(temp!=NULL&&temp->next!=NULL&&temp->next->next!=NULL)
		{
			auxiliary = auxiliary->next;
			temp = temp->next->next;
		}
		temp = auxiliary->next;
		auxiliary->next = NULL;
		while(temp!=NULL)
		{
			helper = temp;
			temp = temp->next;
			helper->next = store;
			store = helper;
		}
		auxiliary->next = store;
	}
	else
	{
		cout<<"only one lele in list\n";
	}
}
int main() {
	struct node* root = NULL;
	insert(&root,1);
	insert(&root,2);
	insert(&root,3);
	insert(&root,4);
	insert(&root,5);
	insert(&root,6);
	insert(&root,7);
	insert(&root,8);
	showdata(root);
	reversehalf(&root);
	cout<<"\n";
	showdata(root);
	
	// your code goes here
	return 0;
}
/*
1 2 3 4 5 6 7 8 
1 2 3 4 8 7 6 5*/