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
/*
Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

*/
class Solution {
public:
    vector<int> solve(TreeNode* r){
        if(!r) return {0,0,9999};
        vector<int> left = solve(r->left);
        vector<int> right = solve(r->right);
        int ml = min(left[1],left[2]);
        int mr = min(right[1],right[2]);
        
        int d0 = left[1]+right[1];// r pr cam nhi h but uske niche ki tree secure h
        int d1 = min(left[2]+mr,right[2]+ml);
        int d2 = 1+min(left[0],ml)+min(right[0],mr);
        return {d0,d1,d2};
    }
    int minCameraCover(TreeNode* root) {
        vector<int> v = solve(root);
        return min(v[1],v[2]);
    }
};