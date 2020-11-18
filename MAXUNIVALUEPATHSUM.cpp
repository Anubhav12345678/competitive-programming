#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode
{
	int val;
	struct TreeNode* left,*right;
	TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};
struct TreeNode* newnode(int n)
{
	struct TreeNode* tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	tmp->val=n;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
int solve(struct TreeNode* root,int &ans)
{
	if(!root)
	return 0;
	int l = solve(root->left,ans);
	int r = solve(root->right,ans);
	int leftmax=0,rightmax=0;
	if(root->left&&root->val==root->left->val)
	leftmax+=l+1;
	if(root->right&&root->val==root->right->val)
	rightmax+=r+1;
	ans = max(ans,leftmax+rightmax);
	return max(leftmax,rightmax);
}
int maxunivaluepathsum(struct TreeNode* root)
{
	int ans=0;
	solve(root,ans);
	return ans;
}
int main() {
	 /* Let us construct a Binary Tree 
        4 
       / \ 
      4   4 
     / \   \ 
    4   9   5 */
  
  TreeNode *root = NULL; 
  root = newnode(4); 
  root->left = newnode(4); 
  root->right = newnode(4); 
  root->left->left = newnode(4); 
  root->left->right = newnode(9); 
  root->right->right = newnode(5); 
  cout << maxunivaluepathsum(root); 
  return 0; 
}