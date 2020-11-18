/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Solution::invertTree(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty())
    {
        TreeNode* t = q.front();
        q.pop();
        swap(t->left,t->right);
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    return A;
    
}
