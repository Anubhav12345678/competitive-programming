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

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

 

Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],
[0,0,0,0,0,null,null,0,0]]
Explanation:



 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2==0)
            return {};
        if(N==1)
            return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i=1;i<N;i+=2)
        {
            for(auto a: allPossibleFBT(i))
            {
                for(auto b:allPossibleFBT(N-i-1) )
                {
                    auto node = new TreeNode(0);
                    node->left = a;
                    node->right=b;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};