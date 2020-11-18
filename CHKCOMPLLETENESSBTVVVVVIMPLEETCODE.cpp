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
    int count(TreeNode* r)
    {
        if(!r)
            return 0;
        return 1+count(r->left)+count(r->right);
    }
    bool solve(TreeNode* r,int ind,int cnt)   
    {
        if(!r)
            return 1;
      if(ind>=cnt)
          return 0;
        return solve(r->left,2*ind+1,cnt)&&solve(r->right,2*ind+2,cnt); 
    }
    bool isCompleteTree(TreeNode* root) {
        return solve(root,0,count(root));
    }
};
/*

Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled,
 and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


*/