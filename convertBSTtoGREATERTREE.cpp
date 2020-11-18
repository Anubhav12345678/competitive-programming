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
    void solve(TreeNode *r,int &preval)
    {
        if(!r)
            return;
        solve(r->right,preval);
        r->val+=preval;
        preval=r->val;
        solve(r->left,preval);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int preval = 0;
        solve(root,preval);
        return root;
    }
};