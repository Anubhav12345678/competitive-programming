/*INTERVIEWBIT*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long long int solve(TreeNode* r,long long int val)
{
    if(!r)
    return 0;
    val= (((val)%1003*10)%1003+(long long int)(r->val)%1003)%1003;
    if(r->left==NULL&&r->right==NULL)
    return val;
    return ((solve(r->left,val))%1003+(solve(r->right,val))%1003);
}
int Solution::sumNumbers(TreeNode* A) {
    long long int x =  solve(A,0LL)%1003;
    return (int)x;
}


















#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};
struct TreeNode * newnode(int n)
{
	struct TreeNode * tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	tmp->val=n;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
int solve(struct TreeNode *root,int val)
{
	if(root==NULL)
	return 0;
	val = val*10+root->val;
	if(root->left==NULL&&root->right==NULL)
	return val;
	return solve(root->left,val)+solve(root->right,val);
}
int allsums(struct TreeNode * root)
{
	return solve(root,0);
}
int main() {
    struct TreeNode *root = newnode(6);  
    root->left = newnode(3);  
    root->right = newnode(5);  
    root->left->left = newnode(2);  
    root->left->right = newnode(5);  
    root->right->right = newnode(4);  
    root->left->right->left = newnode(7);  
    root->left->right->right = newnode(4);  
    cout<<"Sum of all paths is "<<allsums(root);  
    return 0;  
}