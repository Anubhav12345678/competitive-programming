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

Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum 
of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree 
sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.



*/
class Solution {
public:
    int cnt=0;
    map<int,int> sums;
    int dfs(TreeNode* r)
    {
        if(!r)
            return 0;
        int left = dfs(r->left);
        int right = dfs(r->right);
        int sum = r->val+left+right;
        sums[sum]++;
        cnt = max(cnt,sums[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for(auto i = sums.begin();i!=sums.end();i++ )
        {
            if(i->second==cnt)
                res.push_back(i->first);
        }
        return res;
    }
};