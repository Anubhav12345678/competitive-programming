
/*

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.





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
    void solveutil(TreeNode* r,int k,vector<int> &v)
    {
        if(!r||k<0) return;
        if(k==0)
        {
            v.push_back(r->val);
            return;
        }
        solveutil(r->left,k-1,v);
        solveutil(r->right,k-1,v);
    }
    int solve(TreeNode* r,TreeNode* t,int k,vector<int> &v)
    {
        if(!r)
            return -1;
        if(r==t)
        {
          solveutil(r,k,v);
            return 0;
        }
        int dl = solve(r->left,t,k,v);
        if(dl!=-1)
        {
            // dl is the diatsnce of target from root->left
            if(dl+1==k)
            {
                v.push_back(r->val);
            }
            else
                solveutil(r->right,k-dl-2,v);// right node is 2 distance from left node
            return 1+dl;
        }
        int dr = solve(r->right,t,k,v);
        if(dr!=-1)
        {
            if(dr+1==k)
                v.push_back(r->val);
            else
                solveutil(r->left,k-dr-2,v);
            return 1+dr;
        }
        return -1;// if target is not found in the subtrees of root
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root)
            return {};
        vector<int> ans;
        solve(root,target,K,ans);
        return ans;
        
    }
};