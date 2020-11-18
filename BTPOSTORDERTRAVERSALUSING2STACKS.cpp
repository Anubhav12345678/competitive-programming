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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode *t = s1.top();
            s1.pop();
            s2.push(t);
            if(t->left)
                s1.push(t->left);
            if(t->right)
                s1.push(t->right);
        }
        vector<int> res;
        while(!s2.empty())
        {
            TreeNode *t = s2.top();
            res.push_back(t->val);
            s2.pop();
        }
        return res;
    }
};