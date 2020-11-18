/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't 
affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

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
    void solve(TreeNode *t,string &res)
    {
        if(!t)
            return;
        res+=to_string(t->val);
        if(!t->left&&!t->right)
            return;
        // if(t->left)
        // {
        res.push_back('(');
        solve(t->left,res);
        res.push_back(')');
        // }
        if(t->right)
        {
            res.push_back('(');
            solve(t->right,res);
            res.push_back(')');
        }
        return;
    }
    string tree2str(TreeNode* t) {
        string res="";
        solve(t,res);
        return res;
    }
};