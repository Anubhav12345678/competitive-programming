/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
Given a binary tree, flatten it to a linked list in-place.
vector<int> Solution::solve(TreeNode* A, int B) {
    if(!A) return {};
    vector<int> res;
    queue<TreeNode*> q;
    q.push(A);
    bool f=0;
    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left&&cur->left->val==B) f=1;
            else if(cur->right&&cur->right->val==B)  f=1;
            else{
                if(cur->left)
                q.push(cur->left);
                if(cur->right)
                q.push(cur->right);
            }
        }
        if(f) break;
    }
    while(!q.empty())
    {
        res.push_back(q.front()->val);
        q.pop();
    }
    return res;
}
