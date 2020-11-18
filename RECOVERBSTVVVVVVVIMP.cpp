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

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

*/
class Solution {
public:
    void swap(int *a,int *b)
    {
        int t = *a;
        *a=*b;
        *b=t;
    }
    void correctbst(TreeNode* r,TreeNode **f,TreeNode** m,TreeNode **l,TreeNode** prev)
    {
        if(r)
        {
            correctbst(r->left,f,m,l,prev);
            if((*prev)&&r->val<(*prev)->val)
            {
                if(!(*f))
                {
                    *f=*prev;
                    *m = r;
                }
                else
                    *l = r;
            }
            *prev=r;
            correctbst(r->right,f,m,l,prev);
        }
        
    }
    void recoverTree(TreeNode* root) {
        TreeNode *f,*m,*l,*prev;
        f=m=l=prev=NULL;
        correctbst(root,&f,&m,&l,&prev);
        if(f&&l)
            swap(&(f->val),&(l->val));
        else
            swap(&(f->val),&(m->val));
    }
};