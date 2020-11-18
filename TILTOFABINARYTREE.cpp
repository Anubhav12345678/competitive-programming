
/*
The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all 
right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int tilt=0;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        tilt+=abs(l-r);
        return l+r+root->val;
    }
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        solve(root);
        return tilt;
    }
};