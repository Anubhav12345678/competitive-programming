#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
void swap(int *a,int *b)
{
	int tmp = *a;
	*a=*b;
	*b=tmp;
}
struct TreeNode* newnode(int n)
{
	struct TreeNode* tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	tmp->val=n;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
void solve(struct TreeNode* root,struct TreeNode** first,struct TreeNode** middle,struct TreeNode** last,struct TreeNode** prev)
{
	if(root)
	{
		solve(root->left,first,middle,last,prev);
		if(*prev&&(root->val<(*prev)->val))
		{
			if(!(*first))
			{
				*first=*prev;
				*middle=root;
			}
			else
			*last=root;
		}
		*prev=root;
		solve(root->right,first,middle,last,prev);
	}
}
void restore(struct TreeNode* root)
{
	struct TreeNode* first,*middle,*last,*prev;
	first=middle=last=prev=NULL;
	solve(root,&first,&middle,&last,&prev);
	if(first&&last)
	swap(&(first->val),&(last->val));
	else if(first&&middle)
	swap(&(first->val),&(middle->val));
}
void print(struct TreeNode* root)
{
	if(root==NULL)
	return;
	print(root->left);
	cout<<root->val<<" ";
	print(root->right);
}
int main() {
 /*   6 
        /  \ 
       10    2 
      / \   / \ 
     1   3 7  12 
     10 and 2 are swapped 
    */
  
    struct TreeNode *root = newnode(6); 
    root->left        = newnode(10); 
    root->right       = newnode(2); 
    root->left->left  = newnode(1); 
    root->left->right = newnode(3); 
    root->right->right = newnode(12); 
    root->right->left = newnode(7); 
  
    printf("Inorder Traversal of the original tree \n"); 
    print(root); 
  
    restore(root); 
  
    printf("\nInorder Traversal of the fixed tree \n"); 
    print(root); 
  
    return 0; 
}