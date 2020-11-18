/**
 We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.


 */
class Solution {
public:
    int sum(TreeNode* r)
    {
        if(!r)
            return 0;
        return r->val+sum(r->left)+sum(r->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        if(sum(root)==0)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
};