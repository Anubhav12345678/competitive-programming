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
    TreeNode* solve(vector<int> &p)
    {
        int n = p.size();
        if(!n)
            return NULL;
        TreeNode* r = new TreeNode(p[0]);
        int i,j,k,l;
        for( i=1;i<n;i++)
        {
           if(p[i]>p[0])
               break;
        }
        i--;
        vector<int> c1,c2;
        for(j=1;j<=i;j++)
            c1.push_back(p[j]);
        for(j=i+1;j<n;j++)
            c2.push_back(p[j]);
        r->left = solve(c1);
        r->right = solve(c2);
        return r;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder);
    }
};