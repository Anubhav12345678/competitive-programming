/*
Given a binary tree root, a ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right then move to the right child of the current node otherwise move to the left child.
Change the direction from right to left or right to left.
Repeat the second and third step until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.





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
    map<TreeNode*,int> f,g;
    int ans=0;
    void dfs(TreeNode* r)
    {
        if(!r)
            return;
        if(r->left)
        {
            dfs(r->left);
            f[r] = g[r->left]+1;
        }
        else
            f[r]=0;
        if(r->right)
        {
            dfs(r->right);
            g[r] = f[r->right]+1;
        }
        else
            g[r]=0;
        ans = max(ans,max(f[r],g[r]));
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans; 
    }
};