/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    unordered_map<int,int> par;
    void parent(TreeNode* r,int p)
    {
        if(!r)
            return;
        par[r->val]=p;
        parent(r->left,r->val);
        parent(r->right,r->val);
    }
    void fill(TreeNode* r)
    {
         if(!r)
            return;
        int i,j,k,l,lvl=0;
        queue<TreeNode*> q;
        q.push(r);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode *tmp  =q.front();
                q.pop();
                mp[tmp->val] = lvl;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            lvl++;
        }
    }
    // void print(TreeNode* r)
    // {
    //     if(!r)
    //         return;
    //     cout<<"mp["<<r->val<<"] = "<<mp[r->val]<<endl;
    //     print(r->left);
    //     print(r->right);
    // }
    bool isCousins(TreeNode* root, int x, int y) {
        mp.clear();
        par.clear();
        fill(root);
        parent(root,-1);
        // print(root);
        return mp[x]==mp[y]&&par[x]!=par[y];
    }
};