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
    vector<int> solve(TreeNode *r)
    {
        if(r==NULL)
            return {0,0};
        vector<int> l = solve(r->left);
        vector<int> right = solve(r->right);
        vector<int> res(2);
        // res[0] when root is considered
        // res[1] when root is not considered
        res[0] = r->val+l[1]+right[1];
        res[1] = max(l[1],l[0])+max(right[0],right[1]);
        return res;
    }
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> res = solve(root);
        return max(res[0],res[1]);
    }
};