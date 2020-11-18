
/*

Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with 
root A.
 

Example 1:

Input: root = [1,2,3]
Output: [1,2,3]
Explanation: 
The deepest leaves are the nodes with values 2 and 3.
The lowest common ancestor of these leaves is the node with value 1.
The answer returned is a TreeNode object (not an array) with serialization "[1,2,3]".




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
    int d=0;
    TreeNode* lcaDeepestLeaves(TreeNode* root,int x=0) {
        if(!root)
            return NULL;
        if(root->left==root->right)
        {
            d=x;
            return root;
        }
        d=0;
        auto l = lcaDeepestLeaves(root->left,x+1);
        int ld=d;
        d=0;
        auto r = lcaDeepestLeaves(root->right,x+1);
        int rd=d;
        // d=0;
        d=max(ld,rd);
        if(ld>rd) return l;
        if(rd>ld) return r;
        return root;
        
    }
};