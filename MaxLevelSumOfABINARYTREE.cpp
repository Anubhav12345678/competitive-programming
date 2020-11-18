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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
            return 1;
        int i,j,k,l,cnt=0,sum=0,maxi=INT_MIN,maxlevel,lvl=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            cnt = q.size();
            sum=0;
            while(cnt--)
            {
                TreeNode *tmp = q.front();
                sum+=tmp->val;
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            if(sum>maxi)
            {
                maxi=sum;
                maxlevel=lvl;
            }
            lvl++;
        }
        return maxlevel;
        
        
    }
};
//
int maxLevelSum(TreeNode* root)
{
    if(root==NULL)
    return 0;
    queue<TreeNode *root> q;
    q.push(root);
    sum=0,cnt=0,i,j,k,lvl=1,l,maxi= INT_MIN,maxlvl;
    while(!q.empty())
    {
        cnt = q.size();
        sum=0;
        while(cnt--)
        {
            TreeNode *tmp = q.top();
            q.pop();
            sum+=tmp->val;
            if(tmp->left)
            q.push(tmp->left);
            if(tmp->right)
            q.push(tmp->right);
            
        }
        if(sum>maxi)
        {
            maxi=sum;
            maxlvl=lvl;
        }
        lvl++;
    }
    return maxlvl;
}