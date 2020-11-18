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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL&&t2==NULL)
            return NULL;
        int val = ((t1==NULL)?0:t1->val)+((t2==NULL)?0:t2->val);
        TreeNode *newnode = new TreeNode(val);
        newnode->left = mergeTrees(((t1==NULL)?NULL:t1->left),((t2==NULL)?NULL:t2->left));
        newnode->right = mergeTrees(((t1==NULL)?NULL:t1->right),((t2==NULL)?NULL:t2->right));
        return newnode;
    }
};