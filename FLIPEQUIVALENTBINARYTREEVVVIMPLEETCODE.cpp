/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.

 

Example 1:

Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
Flipped Trees Diagram



 */
class Solution {
public:
    bool chk(vector<int> &v1,vector<int> &v2)
    {
        if(v1.size()!=v2.size()) return 0;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i]) return 0;
        }
        return 1;
    }
    void dfs(TreeNode* r,vector<int> &v)
    {
        if(r!=NULL)
        {
            v.push_back(r->val);
            if(r->left==NULL)
            {
                dfs(r->right,v);
            }
            else if(r->right==NULL)
                dfs(r->left,v);
            else if(r->left->val<r->right->val)
            {
                dfs(r->left,v);
                dfs(r->right,v);
            }
            else
            {
                dfs(r->right,v);
                dfs(r->left,v);
            }
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        dfs(root1,v1);
        dfs(root2,v2);
        return chk(v1,v2);
    }
};