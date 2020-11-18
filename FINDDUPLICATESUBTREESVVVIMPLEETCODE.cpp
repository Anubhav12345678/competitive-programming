
/*

Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root 
node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:

      2
     /
    4


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
    vector<TreeNode* > ans;
    string INORDER(TreeNode* r,map<string,int> &m)
    {
        if(!r)
            return "";
        string str = "("+INORDER(r->left,m)+to_string(r->val)+INORDER(r->right,m)+")";
        if(m[str]==1)
            ans.push_back(r);
        m[str]++;
        return str;
            
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        ans.clear();
        map<string,int> m;
        INORDER(root,m);
        return ans;
    }
};