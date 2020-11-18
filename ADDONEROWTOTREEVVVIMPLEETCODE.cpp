/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*

Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d.
 The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value 
v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree
 root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no 
 depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new
 o root's left subtree.



*/
class Solution {
public:
    void solve(int val,TreeNode* t,int dep,int n)
    {
        if(!t) return;
        if(dep==n-1)
        {
            TreeNode* r = t->left;
            t->left = new TreeNode(val);
            t->left->left = r;
            r = t->right;
            t->right = new TreeNode(val);
            t->right->right = r;
            return;
        }
        solve(val,t->left,dep+1,n);
        solve(val,t->right,dep+1,n);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode* t = new TreeNode(v);
            t->right=NULL;
            t->left=root;
            return t;
        }
        solve(v,root,1,d);
        return root;
    }
    
};