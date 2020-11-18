/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*

Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.

NOTE:

Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.


Problem Constraints
1 <= N <= 105

*/
 
TreeNode* Solution::solve(TreeNode* A) {
    if(A==nullptr)
return nullptr;
else if(A->left==nullptr && A->right==nullptr)
return A;
else if(A->left== nullptr)
return solve(A->right);
else if(A->right==nullptr)
return solve(A->left);

    A->left=solve(A->left);
    A->right=solve(A->right);
    
    return A;
}
