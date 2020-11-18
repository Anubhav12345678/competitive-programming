

/*

Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 
represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller 
than "aba".  A leaf of a node is a node that has no children.)

 

Example 1:



Input: [0,1,2,3,4,3,4]
Output: "dba"



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
    string ans="~";
    void dfs(TreeNode* r,string &s)
    {
        if(!r)
         return;
        s.push_back('a'+r->val);
        if(!r->left&&!r->right)
        {
            string p= s;
            reverse(p.begin(),p.end());
            if(p<ans)
                ans=p;
            s.pop_back();
            return;
        }
        dfs(r->left,s);
        dfs(r->right,s);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        dfs(root,s);
        return ans;
    }
};