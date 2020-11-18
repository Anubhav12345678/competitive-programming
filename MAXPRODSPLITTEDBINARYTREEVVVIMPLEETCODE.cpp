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

Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of
 the sums of the subtrees are maximized.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:



Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)




*/
class Solution {
public:
long long sum,ans=0;long long dfs(TreeNode* r)
    {
        if(!r)
            return 0;
        return (r->val+dfs(r->left)+dfs(r->right));
    }
long long solve(TreeNode* r)
    {
        if(!r)
            return 0;
        auto ret = (r->val+solve(r->left)+solve(r->right));
        ans= max(ans,(ret*(sum-ret)));
        return ret;
    }
    int maxProduct(TreeNode* root) {
        sum = dfs(root);
        // cout<<sum<<endl;
        ans=0;
        solve(root);
        long long int mod = 1e9 + 7;
        return ans%mod;
    }
};