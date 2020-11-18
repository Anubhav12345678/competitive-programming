/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int h;
 int height(TreeNode *h)
 {
     if(h==NULL)
     return 0;
     return 1+max(height(h->left),height(h->right));
 }
 bool bal(TreeNode* h)
 {
     if(h==NULL)
     return  true;
     if(h->left==NULL&&h->right==NULL)
     return true;
     if(bal(h->left)&&bal(h->right)&&(abs(height(h->left)-height(h->right))<=1))
     return true;
     else
     return false;
 }
int Solution::isBalanced(TreeNode* A) {
    return bal(A);

}
