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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        st1.push(root);
        vector<vector<int>> res;
        if(!root)
            return res;
        while(!st1.empty()||!st2.empty())
        {
            vector<int> tmp;
            while(!st1.empty())
            {
                TreeNode *v = st1.top();
                st1.pop();
                tmp.push_back(v->val);
                if(v->left)
                    st2.push(v->left);
                if(v->right)
                    st2.push(v->right);
            }
            if(tmp.size()!=0)
            res.push_back(tmp);
            tmp.clear();
            while(!st2.empty())
            {
                TreeNode *v = st2.top();
                st2.pop();
                tmp.push_back(v->val);
                if(v->right)
                    st1.push(v->right);
                if(v->left)
                    st1.push(v->left);
            }
            if(tmp.size()!=0)
            res.push_back(tmp);
            tmp.clear();
        }
        return res; 
    }
};