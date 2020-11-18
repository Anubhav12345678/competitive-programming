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

Given a binary tree with N nodes, each node has a different value from {1, ..., N}.

A node in this binary tree can be flipped by swapping the left child and the right child of that node.

Consider the sequence of N values reported by a preorder traversal starting from the root.  Call such a sequence of N values 
the voyage of the tree.

(Recall that a preorder traversal of a node means we report the current node's value, then preorder-traverse the left child,
 then preorder-traverse the right child.)

Our goal is to flip the least number of nodes in the tree so that the voyage of the tree matches the voyage we are given.

If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.

If we cannot do so, then return the list [-1].

 

Example 1:



Input: root = [1,2], voyage = [2,1]
Output: [-1]



*/
class Solution {
public:
   int look;
    vector<int> v;
    bool can;
    vector<int> ans;
    inline void dfs(TreeNode *b){
        if(v[look]!=b->val){
            can=true;
            return;
        }
        look++;
        if(b->left&&b->right){
            if(b->left->val==v[look]){
                dfs(b->left);
                dfs(b->right);
            }
            else{
                dfs(b->right);
                dfs(b->left);
                ans.push_back(b->val);
            }
            return;
        }
        if(b->left){
            dfs(b->left);
        }
        if(b->right){
            dfs(b->right);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        can=false;
        look=0;
        ans.clear();
        v=voyage;
        dfs(root);
        if(can){
            ans.clear();
            ans.push_back(-1);
            return ans;
        }
        return ans;
    }
};