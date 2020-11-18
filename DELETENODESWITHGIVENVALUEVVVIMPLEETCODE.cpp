

/*

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if it's parent node becomes a leaf node and has the value
 target, it should also be deleted (you need to continue doing that until you can't).

 

Example 1:



Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).


We traverse the tree in postorder fashion and recursively delete the nodes. The approach is very similar to this and this problem.
filter_none


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
    TreeNode* solve(TreeNode* r,int t)
    {
        if(!r)
            return NULL;
        r->left=solve(r->left,t);
        r->right=solve(r->right,t);
        if(r->val==t&&r->left==NULL&&r->right==NULL)
        {
            // delete(r);
            return NULL;
        }
        return r;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
       solve(root,t);
        if(root->val==t&&!root->left&&!root->right)
            return NULL;
        return root;
    }
};