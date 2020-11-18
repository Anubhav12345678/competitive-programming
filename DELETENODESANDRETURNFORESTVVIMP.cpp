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
    vector<TreeNode*> res;
    void solve(TreeNode *node,TreeNode* par,set<int> s,bool isroot,bool isleft)
    {
        if(node==NULL)
            return;
        if(s.find(node->val)==s.end())
        {
          if(isroot)
          {
              res.push_back(node);
              isroot=false;
          }
          solve(node->left,node,s,isroot,true);
          solve(node->right,node,s,isroot,false);
        }
        else
        {
            if(isleft)
            {
                if(par!=NULL)
                    par->left=NULL;
            }
            else
            {
                if(par!=NULL)
                    par->right=NULL;
            }
           solve(node->left,node,s,true,true);
          solve(node->right,node,s,true,false); 
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        res.clear();
        set<int> s;
        for(auto i:to_delete)
        {
            s.insert(i);
        }
        solve(root,NULL,s,true,true);
        return res;
    }
};