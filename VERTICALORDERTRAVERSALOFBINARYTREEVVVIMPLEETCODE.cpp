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
    void pre(TreeNode* root, auto &ma, int dist,int level)
    {
        if(root==nullptr)
            return;
        ma[dist].push_back({root->val,level});
        pre(root->left,ma,dist-1,level+1);
        pre(root->right,ma,dist+1,level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     map<int,vector<pair<int,int>>> ma;
        pre(root,ma,0,0);
        vector<vector<int>> vec;
        for(auto it:ma)
        {
            sort(it.second.begin(),it.second.end(),[](const auto& lhs, const auto& rhs){
                if(lhs.second < rhs.second)
                    return true;
                else if(lhs.second==rhs.second)
                    return lhs.first < rhs.first;
                else
                    return false;
            });
            vector<int> temp;
            for(auto itr:it.second)
                temp.push_back(itr.first);
            vec.push_back(temp);
        }
        return vec;   
    }
};


//me
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
    static bool comp(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.second<p2.second)
            return 1;
        else if(p1.second==p2.second)
            return p1.first<p2.first;
        return 0;
    }
    void solve(TreeNode* r,map<int,vector<pair<int,int>>> &mp,int hd,int level)
    {
        if(!r)
            return;
        mp[hd].push_back({r->val,level});
        solve(r->left,mp,hd-1,level+1);
        solve(r->right,mp,hd+1,level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        solve(root,mp,0,0);
        int i,j,k,l;
        vector<vector<int>> res;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            
            sort(it->second.begin(),it->second.end(),comp);
            vector<int> tmp;
            for(int i=0;i<it->second.size();i++)
            {
                tmp.push_back(it->second[i].first);
            }
            res.push_back(tmp);
        }
        return res;
    }
};


//INTERVIEWBIT SOL
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {

vector< vector<int>> ans;

if( A == NULL )
    return ans;

queue< pair< TreeNode*, int>> q;
map < int, vector<int>> levelorder;

q.push( make_pair( A, 0 ) );

while( !q.empty() ){
    
    pair<TreeNode*, int> qvar;
    qvar = q.front();
    q.pop();
    
    levelorder[ qvar.second ].push_back( qvar.first->val );
    
    if( qvar.first->left != NULL ){
        
        q.push( make_pair( qvar.first->left, qvar.second-1 ) );
    }
    
    if( qvar.first->right != NULL ){
        
        q.push( make_pair( qvar.first->right, qvar.second+1 ) );
    }
    
}

for( auto it=levelorder.begin(); it != levelorder.end(); it++ ){
    
    ans.push_back( it->second );
}


return ans;
}