/*

Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices.
 You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend in order 
 to collect all apples in the tree starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge
 connecting the vertices fromi and toi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means
  that vertex i has an apple, otherwise, it does not have any apple.


*/
class Solution {
public:
    int sz[100005];
    int ans=0;
    void dfs(vector<vector<int>> &v,int x,int pre,vector<bool> &ha)
    {
        sz[x] = ha[x]?1:0;
        for(auto y:v[x])
        {
            if(y==pre)
                continue;;
            dfs(v,y,x,ha);
            sz[x]+=sz[y];
        }
    }
    
    // for cal the res time
    void dfs2(vector<vector<int>> &v,int x,int pre)
    {
        for(auto y:v[x])
        {
            if(y==pre) continue;
            if(sz[y])
            {
                ans+=2;
                dfs2(v,y,x);
            }
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> v(n);
        int i,j,k,l,m=edges.size();
        for(auto it:edges)
        {
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        // for(i=0;i<n;i++)
        //     cout<<"i = "<<i<<" "<<sz[i]<<" ";
        memset(sz,0,sizeof(sz));
        dfs(v,0,-1,hasApple);
        for(i=0;i<n;i++)
            cout<<"i = "<<i<<" "<<sz[i]<<endl;
         ans=0;
        dfs2(v,0,-1);
        return ans;
        
        
    }
};