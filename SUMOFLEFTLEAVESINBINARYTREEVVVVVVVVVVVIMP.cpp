/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isleaf(TreeNode* node)
    {
        if(!node)
            return 0;
        if(!node->left&&!node->right)
            return 1;
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        if(root!=NULL)
        {
            if(isleaf(root->left))
                ans+=root->left->val;
            else
                ans+=sumOfLeftLeaves(root->left);
            ans+=sumOfLeftLeaves(root->right);
        }
        return ans;
        // int ansn=0;
        // if(root->left)
        //     ans+=sumofLeftLeaves(root->left);
        // if(root->right)
        //     root=root->right;
            
        
    }
};