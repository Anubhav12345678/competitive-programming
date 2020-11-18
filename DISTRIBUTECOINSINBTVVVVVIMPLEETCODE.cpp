/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*

Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another. 
 (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.

 

Example 1:



Input: [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.



*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    int solve(TreeNode* r)
    {
        if(!r)
            return 0;
        int left = solve(r->left);
        int right = solve(r->right);
        ans+=abs(left+right+r->val-1);
        return left+right+r->val-1;
    }
    int distributeCoins(TreeNode* root) {
        ans=0;
        solve(root);
        return ans;
    }
};






class Solution {
public:
    int moves=0;
    // solve fun gives the number of extra coins in the subtree rooted at root
    int solve(TreeNode* node) {
        // left is extra coins at or in subtree of root->left
        // right is extra coins at or in subtree of root->right
        if(!node) return 0;
        int left = solve(node->left);
        int right = solve(node->right);
        moves += (abs(left) + abs(right));
        return node->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        // if(root==NULL) return 0;
        // int ans=0;
        moves=0;
        solve(root);
        return moves;
        // int l = distributeCoins(root->left);
        // int r = distributeCoins(root->right);
        // ans+=abs(l)+abs(r);
        
    }
};