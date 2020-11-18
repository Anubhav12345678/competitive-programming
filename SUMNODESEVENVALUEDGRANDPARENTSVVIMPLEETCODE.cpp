


/*


Given a binary tree, return the sum of values of nodes with even-valued grandparent. 
 (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.

 

Example 1:



Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.




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
    int solve(TreeNode *r)
    {
        if(!r)
            return 0;
        int x = 0,y=0;
        if(r->val%2==0)
        {
            // int x = 0,y=0;
            if(r->left)
            {
                if(r->left->left)
                    x+=r->left->left->val;
                if(r->left->right)
                    x+=r->left->right->val;
            }
            if(r->right)
            {
                if(r->right->left)
                    y+=r->right->left->val;
                if(r->right->right)
                    y+=r->right->right->val;
            }
        }
        return x+y+solve(r->left)+solve(r->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root);
    }
};