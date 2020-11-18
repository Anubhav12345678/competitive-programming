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

Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where 
V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

Example 1:



Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.




 */
class Solution {
public:
    int ans=INT_MIN;
    void solve1(TreeNode* n1,TreeNode* n2)
    {
        if(!n2) return;
        ans = max(ans,abs(n1->val-n2->val));
        solve1(n1,n2->left);
        solve1(n1,n2->right);
    }
    void solve(TreeNode* r)
    {
        if(!r)
            return;
        solve1(r,r);
        solve(r->left);
        solve(r->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
};