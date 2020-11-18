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
    string s;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> vec;
        vec.clear();
        solve(root,vec);
        return vec;
    }
    void solve(TreeNode *root,vector<string> &v)
    {
        if(!root) return;
        if(!root->left&&!root->right)
        {
            s+=to_string(root->val);
            v.push_back(s);
        }
        else
        {
            s+=to_string(root->val);
            s+="->";
        }
        string cur = s;
        solve(root->left,v);
        s=cur;
        solve(root->right,v);
    }
};