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
    bool isleaf(TreeNode *root)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL&&root->right==NULL)
            return true;
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0;
        if(root!=NULL)
        {
            if(isleaf(root->left))
                res+=root->left->val;
            else
                res+=sumOfLeftLeaves(root->left);
            
            res+=sumOfLeftLeaves(root->right);
        }
        return res;
    }
};