class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> cnt;
    vector<int> dis;
    void dfs1(int x,int p)
    {
        for(auto y:adj[x])
        {
            if(y==p) continue;
            dfs1(y,x);
            cnt[x]+=cnt[y];
            dis[x]+=dis[y]+cnt[y];
        }
    }
    void dfs2(int x,int p)
    {
        for(auto y:adj[x]){
            if(y==p) continue;
            dis[y] =dis[x]-cnt[y]+n-cnt[y];
            dfs2(y,x);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        adj.resize(N);
        cnt.resize(N,1);
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dis.resize(N);
        n=N;
        dfs1(0,-1);
        dfs2(0,-1);
        return dis;
        
    }
};
/*

An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.

The ith edge connects nodes edges[i][0] and edges[i][1] together.

Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.

Example 1:

Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: 
Here is a diagram of the given tree:
  0
 / \
1   2
   /|\
  3 4 5
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.


*/