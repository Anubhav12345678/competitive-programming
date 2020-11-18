/*
Given an undirected tree with an even number of nodes. Consider each connection between a parent and child node to be an edge.

You need to remove maximum number of these edges, such that the disconnected subtrees that remain each have an even number of nodes.

Return the maximum number of edges you can remove.

*/


vector<int> d;
vector<vector<int>> g;
int cnt=0;
void dfs(int u,int par){
    d[u]=0;
    for(auto v:g[u]){
        if(v==par) continue;
        dfs(v,u);
        d[u]+=d[v];// d[v] is number of nodes on subtree of v
        if(d[v]%2==0)
        cnt++;
    }
    d[u]++;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    d = vector<int>(A,0);
    g= vector<vector<int>>(A);
    
    for(auto e:B){
        g[e[0]-1].push_back(e[1]-1);
        g[e[1]-1].push_back(e[0]-1);
    }
    cnt=0;
    dfs(0,-1);
    return cnt;
    
    
    
}
