/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 




*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* t)
{
    if(t&&t->left==NULL&&t->right==NULL)
    return 1;
    if(!t)
    return 10000007;
    // if(t&&t->left==NULL&&t->right==NULL)
    // return 0;
    return 1+min(solve(t->left),solve(t->right));
}
int Solution::minDepth(TreeNode* A) {
    return solve(A);
}
