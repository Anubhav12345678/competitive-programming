/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 map<int,vector<int>> mp;
void solve1(TreeNode* t,int x,int y)
{
    if(!t) return;
    mp[x-y].push_back(t->val);
    solve1(t->left,x+1,y-1);
    solve1(t->right,x+1,y+1);
}
vector<int> Solution::solve(TreeNode* A) {
    if(!A) return {};
    mp.clear();
    solve1(A,0,0);
    vector<int> res;
    for(auto it = mp.begin();it!=mp.end();it++)
    {
        vector<int> tmp = it->second;
        for(auto i:tmp)
        res.push_back(i);
    }
    return res;
}
