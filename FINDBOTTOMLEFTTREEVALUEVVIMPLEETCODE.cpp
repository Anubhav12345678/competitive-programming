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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            res.push_back(v);
        }
        return res[res.size()-1][0];
    }
};  

//DFS
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
    int highlvl=-1;
    int ele=0;
    void solve(TreeNode* r,int lvl)
    {
        if(!r)
            return;
        if(lvl>highlvl) {highlvl = lvl; ele=r->val;}
        solve(r->left,lvl+1);
        solve(r->right,lvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        solve(root,0);
        return ele;
    }
};