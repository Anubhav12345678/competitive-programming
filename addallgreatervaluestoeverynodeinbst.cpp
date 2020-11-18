#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<stdlib.h>
// view https://ideone.com/XwgHFz for full code and output
struct node
{
	ll data;
	struct node *l,*r;
};
struct node* newnode(ll data)
{
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->data = data;
	t->l=NULL;
	t->r=NULL;
	return t;
}
void modify(struct node* root,ll *sum)// doing this the reverse inorder traversal
{
	if(root==NULL)
	return;
	modify(root->r,sum);//now sum contains sum of all nodes graeter or equal to the root
	*sum = *sum+root->data;
	root->data = *sum;
	modify(root->l,sum);
	
}
void modifytree(struct node* root)
{
	ll sum=0;
	modify(root,&sum);
}
struct node* insert(struct node* root,ll data)
{
	if(root==NULL) return newnode(data);
	if(root->data>=data)
	root->l = insert(root->l,data);
	else
	root->r = insert(root->r,data);
	return root;
}
void inorder(struct node* root)
{
	if(root==NULL)
	return;
	inorder(root->l);
	cout<<root->data<<" ";
	inorder(root->r);
}
int main() {
	struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
    modifytree(root); 
  
    // print inoder tarversal of the modified BST 
    inorder(root); 
  
    return 0;
}
//OUTPUT 350 330 300 260 210 150 80