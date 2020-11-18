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
    bool isleaf(TreeNode *node)
    {
        if(node==NULL)
            return false;
        return node->left==NULL&&node->right==NULL;
    }
    int solve(TreeNode *root,int cur)
    {
        if(!root)
            return 0;
        cur*=2;
        cur+=root->val;
        if(isleaf(root))
            return cur;
        else
            return solve(root->left,cur)+solve(root->right,cur);
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,0);
    }
};