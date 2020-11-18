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
    bool solve(TreeNode* r,vector<int> &v,int ind)
    {
        if(!r)
            return 0;
        if(ind==v.size()-1)
        {
            return (r->left==NULL&&r->right==NULL)&&v[ind]==r->val;
        }
        // if(ind>=v.size())
        if(v[ind]!=r->val)
            return 0;
        return solve(r->left,v,ind+1)||solve(r->right,v,ind+1);
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int i,j,k,l,n=arr.size();
        return solve(root,arr,0);
        
    }
};

/*

Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree. 

We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.

 

Example 1:



Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation: 
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -> 1 -> 1 -> 0 
0 -> 0 -> 0


*/