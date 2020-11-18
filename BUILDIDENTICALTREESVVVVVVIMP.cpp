/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int cnt(TreeNode* t)
 {
     if(!t)
     return 0;
     return 1+cnt(t->left)+cnt(t->right);
 }
 bool f=1;
 int solve(TreeNode* t1,TreeNode* t2)// t1 ko t2 me bdalna h
 {
     if(!t2&&!t1)
     return 0;
     if(t1&&!t2)
     {
         f=0;
         return 0;
     }
     if(!t1&&t2)
     {
         return cnt(t2);
     }
     return solve(t1->left,t2->left)+solve(t1->right,t2->right);
 }
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    f=1;
    int x = solve(A,B);
    if(f==0)
    return -1;
    return x;
}
