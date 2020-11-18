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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int ans = 1;
        while (!q.empty()) {
            int n = q.size();
            
            // handle integer overflow
            if (n == 1) {
                pair<TreeNode*, int> node = q.front();
                q.pop();
                q.push({node.first, 1});
            }

            ans = max (ans, q.back().second - q.front().second + 1);
            for (int i = 0; i < n; i++) {
                pair<TreeNode*, int> node = q.front();
                q.pop();
                if (node.first->left) q.push({node.first->left, node.second * 2});
                if (node.first->right) q.push({node.first->right, node.second * 2 + 1});
            }
        }

        return ans;
    }
};