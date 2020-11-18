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
    vector<TreeNode*> solve(int st,int en)
    {
        vector<TreeNode*> res;
        if(st>en)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=st;i<=en;i++)
        {
            vector<TreeNode*> left = solve(st,i-1);
            vector<TreeNode*> right = solve(i+1,en);
            for(int j=0;j<left.size();j++)
            {
                TreeNode * x = left[j];
                for(int k=0;k<right.size();k++)
                {
                    TreeNode * y = right[k];
                    TreeNode * node = new TreeNode(i);
                    node->left = x;
                    node->right = y;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
        {
            vector<TreeNode*> res;
            return res;
        }
        return solve(1,n);
    }
};