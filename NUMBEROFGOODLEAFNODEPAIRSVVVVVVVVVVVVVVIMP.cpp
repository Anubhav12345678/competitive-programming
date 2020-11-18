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
Given the root of a binary tree and an integer distance. A pair of two different
 leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

*/
class Solution {
public:
    int ans=0;
    vector<int> help(int d,TreeNode* r){
        if(!r) return {0};
        if(r->left==NULL&&r->right==NULL) return {1};
        auto left = help(d,r->left);
        auto right = help(d,r->right);
        for(auto a:left){
            for(auto b:right){
                if(a&&b&&(a+b)<=d) ans++;
            }
        }
        vector<int> res;
        for(auto a:left)
            if(a&&(a+1)<d) res.push_back(a+1);
        
        for(auto a:right)
            if(a&&(a+1)<d) res.push_back(a+1);
        return res;
        
    }
    int countPairs(TreeNode* root, int distance) {
        help(distance,root);
        return ans;
    }
};