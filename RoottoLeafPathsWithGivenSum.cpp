/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// em
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
#define ll long long
class Solution {
public:
    void solve(vector<vector<int>> &p,vector<int> &s,TreeNode* r,int sum)
    {
        if(!r)
            return;
        int rem = sum-r->val;
        if(r->left==NULL&&r->right==NULL)
        {
            if(rem==0)
            {
                s.pb(r->val);
                p.pb(s);
                s.pop_back();
                return;
            }
            else
                return;
        }
        s.pb(r->val);
        solve(p,s,r->left,rem);
        s.pop_back();
        s.pb(r->val);
        solve(p,s,r->right,rem);
        s.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> p;
        if(!root)
            return p;
        vector<int> s;
        s.clear();
        solve(p,s,root,sum);
        return p;
        
        
    }
};

void pathhelp(TreeNode *t,int sum,vector<vector<int>> &res,vector<int> &cur)
{
    if(t==NULL)
    return;
    int remain = sum-t->val;
    cur.push_back(t->val);
    if(t->left==NULL&&t->right==NULL)
    {
        if(remain==0)
        {
            res.push_back(cur);
            // cur.pop_back();
        }
        cur.pop_back();
        return;
    }
    pathhelp(t->left,remain,res,cur);
    pathhelp(t->right,remain,res,cur);
    cur.pop_back();
    return;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> cur;
    pathhelp(A,B,res,cur);
    return res;
}
